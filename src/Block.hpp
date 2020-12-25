#define BlockSize 32
#include <SDL.h>
class Block
{
private:
    /* data */
public:
    Block(int x,int y,Uint8 _r,Uint8 _g,Uint8 _b,Uint8 _a);
    SDL_Rect _Rect;
    SDL_Color _Color;
    Draw(SDL_Renderer *render);
    ChangeColor(Uint8 _r,Uint8 _g,Uint8 _b,Uint8 _a);
    ~Block();
};

Block::Block(int x,int y,Uint8 _r,Uint8 _g,Uint8 _b,Uint8 _a)
{
    _Rect.x = x;
    _Rect.y = y;
    _Rect.w = BlockSize;
    _Rect.h = BlockSize;
    _Color.a = _a;
    _Color.r = _r;
    _Color.g = _g;
    _Color.b = _b;
}

Block::ChangeColor(Uint8 _r,Uint8 _g,Uint8 _b,Uint8 _a)
{
    _Color.a = _a;
    _Color.r = _r;
    _Color.g = _g;
    _Color.b = _b;
}


Block::Draw(SDL_Renderer *render)
{
    SDL_SetRenderDrawColor(render, _Color.r, _Color.g, _Color.b, _Color.a);
    SDL_RenderFillRect(render,&_Rect);
}

Block::~Block()
{
}
