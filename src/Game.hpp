#include <iostream>
#include <SDL.h>
#include <vector>
#include "Block.hpp"
#include "Button.hpp"



class Game
{
public:
    int _Largeur;
    int _Hauteur;
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    SDL_Event event;
    bool launched = true;
    Game(int largeur,int hauteur);
    Render(int r,int g,int b);
    FindClose(int find);
    SetColorBlock(Uint8 _r,Uint8 _g,Uint8 _b);
    InitMap();
    Event();
    Update();
    ~Game();
    int mouseX;
    int mouseY;
    std::vector<Block> ListBlock;
    std::vector<Button> ListButton;
    SDL_Color activeColor= {0,0,255,255};
    //640 en w et 640 en h
    int NombreBlockMax = 20;
    std::vector<int> v = {-32,0,32,64,96,128,160,192,224,256,288,320,352,384,416,448,480,512,544,576,608,640};
    bool pressedLeftCLick = false;
    bool pressedRightClick = false;
    int counter = 0;
    
    
    const int FPS = 60;
    const int frameDelay = 1000/FPS;

    Uint32 frameStart;
    int frameTime;
    
};

Game::Game(int largeur,int hauteur)
{
    
    _Largeur = largeur;
    _Hauteur = hauteur;
    if (SDL_Init(SDL_INIT_EVERYTHING) !=0)
    {
        exit(EXIT_FAILURE);
    }
    SDL_CreateWindowAndRenderer(largeur,hauteur,0,&window,&renderer);

    ListButton.push_back(Button(680,25,100,35,0,0,0,255)); //Noir
    //ListButton.push_back(Button(644,100,125,35,255,255,255,255)); //Blanc
    ListButton.push_back(Button(680,125,100,35,255,0,0,255)); //rouge
    ListButton.push_back(Button(680,225,100,35,0,255,0,255)); //vert
    ListButton.push_back(Button(680,325,100,35,0,0,255,255)); //bleu
    ListButton.push_back(Button(680,425,100,35,255,255,0,255)); //jaune

    //InitMap();
}

Game::Event()
{
    while(SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            launched = false;
        }
        if(event.type == SDL_MOUSEMOTION)
        {
            mouseX = event.motion.x-16;
            mouseY = event.motion.y-16;
        }
        if(event.type == SDL_MOUSEBUTTONDOWN)
        {
            if(event.button.button == SDL_BUTTON_LEFT)
            {
                pressedLeftCLick = true;
            }
            if (event.button.button == SDL_BUTTON_RIGHT)
            {
                pressedRightClick = true;
            }
        }
        if(event.type == SDL_MOUSEBUTTONUP)
        {
            if(event.button.button == SDL_BUTTON_LEFT)
            {
                pressedLeftCLick = false;
            }
            if(event.button.button == SDL_BUTTON_RIGHT)
            {
                pressedRightClick = false;
            }
        }
        if (event.type == SDL_KEYDOWN)
        {
            if (event.key.keysym.sym == SDLK_SPACE)
            {
                std::cout << "Oui" << std::endl;
            }
        }
    }
}

Game::Update()
{
    if(pressedLeftCLick==true)
    {
        if(FindClose(mouseX) != 640)
        {
            ListBlock.push_back(Block(FindClose(mouseX),FindClose(mouseY),activeColor.r,activeColor.g,activeColor.b,activeColor.a));
        }
        
    }
    
    if(pressedRightClick == true)
    {
        counter = 0;
        for(auto& value : ListBlock)
        {
            if(value._Rect.x == FindClose(mouseX) && value._Rect.y == FindClose(mouseY))
                ListBlock.erase(ListBlock.begin() + counter);
            counter += 1;
        }
    }
    
    
    for(auto& it : ListButton)
    {
        if (it.Collision(mouseX,mouseY) == true && pressedLeftCLick == true)
        {
            /*prend la couleur du button*/
            activeColor = it._Color;
        }
    }
}


Game::SetColorBlock(Uint8 _r,Uint8 _g,Uint8 _b)
{
    activeColor = {_r,_g,_b,activeColor.a};
}

Game::InitMap()
{
    for(int i=0;i<NombreBlockMax;i++)
    {
        for(int j=0;j<NombreBlockMax;j++)
        {
            if(i==0 or j==0 or j==20 or i == 20)
            {
                ListBlock.push_back(Block(i*32,j*32,activeColor.r,activeColor.g,activeColor.b,activeColor.a));
            }
        }
    }
}

Game::Render(int r,int g,int b)
{
    frameStart = SDL_GetTicks();
    
    SDL_SetRenderDrawColor(renderer, r, g, b, 255 );
    SDL_RenderClear(renderer);
    for(auto& it : ListBlock)
    {
        it.Draw(renderer);
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255 );

    for(int i=1;i<NombreBlockMax+1;i++)
    {
        SDL_RenderDrawLine(renderer,-10,i*32,640,i*32);
    }
    for(int i=1;i<NombreBlockMax+1;i++)
    {
        SDL_RenderDrawLine(renderer,i*32,-10,i*32,640);
    }

    for(auto& it : ListButton)
    {
        it.Draw(renderer);
    }
    
    SDL_RenderPresent(renderer);

    frameTime = SDL_GetTicks() - frameStart;

    if(frameDelay > frameTime)
    {
        SDL_Delay(frameDelay-frameTime);
    }
}
Game::FindClose(int find)
{
    int best;
    int counter = 0;
    int TestMinimal = find - v[0];

    for(auto& value : v)
    {
        
        if(abs(find - value) == 0)
        {
            best = counter;
        }      
        else
        {
            if(abs(find - value)<TestMinimal)
            {
                TestMinimal = abs(find - value);
                best = counter;
            }
        }
        
        counter +=1;
    }
    return v[best];
}

Game::~Game()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
