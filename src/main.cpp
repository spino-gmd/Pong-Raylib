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
    float width, height;
};

Ball ball;
Paddle rect;

int main()
{
    const int scr_x = 1100;
    const int scr_y = 1000;
    int cont = 0;
    bool lost = false;


    InitWindow(scr_x, scr_y, "Projeto Raylib");

    Color verde = {15,150,67,255};

    // Bola
    ball.position = {scr_x / 2, scr_y / 4};
    ball.speed_x = ball.speed_y = 8;
    ball.radius = 25;

    // Paddle
    rect.width = 300;
    rect.height = 30;
    rect.x = scr_x / 2 - rect.width / 2;

    SetTargetFPS(90);

    while (!WindowShouldClose())
    {
        
        if(!lost){
        Rectangle pad = {rect.x,950,rect.width,rect.height};
        // Eventos
        if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) rect.x += 5.5;
        else if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) rect.x -= 5.5;

        // Movimento da bola
        ball.position.x += ball.speed_x;
        ball.position.y += ball.speed_y;

        // Colisão com as paredes
        if (ball.position.x >= scr_x || ball.position.x <= 0) ball.speed_x *= -1;
        if (ball.position.y <= 0) ball.speed_y *= -1;

        if (ball.position.y >= scr_y){
            ball.position = {scr_x / 2, scr_y / 4};
            cont = 0;
            lost = true;
        }

        // Colisão com o paddle
        if (CheckCollisionCircleRec(ball.position, ball.radius, pad)){
            ball.speed_y *= -1;
            cont++;
        }
    }
        // Desenho
        BeginDrawing();
        ClearBackground(verde);

        if (lost){
            int larg2 = MeasureText("Você perdeu!", 120);
            int larg3 = MeasureText("Aperte ENTER para continuar",60);
            DrawText("Você perdeu!", (scr_x - larg2) / 2, scr_y / 2, 120, WHITE);
            DrawText("Aperte ENTER para continuar", (scr_x - larg3) / 2, scr_y / 4, 60, WHITE);
            if(IsKeyDown(KEY_ENTER)){
            lost = false;
            if(rect.x >= scr_x/2) ball.speed_x = 6;
            else ball.speed_x = -6;
            }
        }else{

        DrawCircleV(ball.position, ball.radius, WHITE);
        DrawRectangle(rect.x,950,rect.width,rect.height,WHITE);

        int larg1 = MeasureText("Pong", 40);
        DrawText("Pong", (scr_x - larg1)/2, 50, 40, WHITE);
        DrawText(TextFormat("%d",cont), 10, 10, 40, WHITE);
        }
        EndDrawing();
}

    CloseWindow();

    return 0;
}