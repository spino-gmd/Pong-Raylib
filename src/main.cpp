#include <raylib.h>
#include <iostream>

class Ball
{
    public:
    Vector2 position;
    int speed_x, speed_y;
    int radius;
};

class Paddle
{
    public:
    float x;
    int width, height;
};

Ball ball;
Paddle rect;

int main()
{
    const int scr_x = 1000;
    const int scr_y = 800;
    int cont = 0;
    float time_ran = 0;
    bool lost = false;
    bool low = false;


    InitWindow(scr_x, scr_y, "Projeto Raylib");

    Color verde = {15,150,67,255};

    // Bola
    ball.position = {scr_x / 2, scr_y / 2};
    ball.speed_x = ball.speed_y = 6;
    ball.radius = 25;

    // Paddle
    rect.width = 250;
    rect.height = 30;
    rect.x = scr_x / 2 - rect.width / 2;

    SetTargetFPS(120);

    while (!WindowShouldClose())
    {

        if(low){
        ball.speed_x = ball.speed_y = 2.5;
        time_ran += GetFrameTime();
        }

        if(time_ran >= 2.3){
        ball.speed_x = ball.speed_y = 6;
        time_ran = 0;
        low = false;
        }

        // Eventos
        if (IsKeyDown(KEY_RIGHT)) rect.x += 5;
        else if (IsKeyDown(KEY_LEFT)) rect.x -= 5;

        // Movimento da bola
        ball.position.x += ball.speed_x;
        ball.position.y += ball.speed_y;

        // Colisão com as paredes
        if (ball.position.x >= scr_x || ball.position.x <= 0) ball.speed_x *= -1;
        if (ball.position.y <= 0) ball.speed_y *= -1;

        if (ball.position.y >= scr_y){
            ball.position = {scr_x / 2, scr_y / 2};
            cont = 0;
            lost = true;
        }

        // Colisão com o paddle
        Rectangle pad = {rect.x,750,rect.width,rect.height};

        if (CheckCollisionCircleRec(ball.position, ball.radius, pad)){
            ball.speed_y *= -1;
            cont++;
        }

        // Desenho
        BeginDrawing();

        if (lost){
            int larg1 = MeasureText("Você perdeu!", 120);
            DrawText("Você perdeu!", (scr_x - larg1) / 2, scr_y / 2, 120, WHITE);
            lost = false;
            low = true;
            EndDrawing();
            WaitTime(1.0);
        }else{

        ClearBackground(verde);

        DrawCircleV(ball.position, ball.radius, WHITE);
        DrawRectangle(rect.x,750,rect.width,rect.height,WHITE);

        int larg2 = MeasureText("Pong", 40);
        DrawText("Pong", (scr_x - larg2)/2, 50, 40, WHITE);
        DrawText(TextFormat("%d",cont), 10, 10, 40, WHITE);
        }
        EndDrawing();
}

    CloseWindow();

    return 0;
}