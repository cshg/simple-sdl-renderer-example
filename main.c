#include <stdio.h>
#include <SDL.h>

void filledRect(void *r_in,
                int x, int y, int w, int h,
                int r, int g, int b, int a)
{
    SDL_Renderer* renderer = (SDL_Renderer*)r_in;
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
    SDL_Rect rect = { x, y, w, h };
    SDL_RenderFillRect(renderer, &rect);
}

int main(int argc, char* args[]) {
  SDL_Init(SDL_INIT_VIDEO);

  int width = 640;
  int height = 480;
  SDL_Window *window = SDL_CreateWindow(
          "mainWindow",
          SDL_WINDOWPOS_CENTERED,
          SDL_WINDOWPOS_CENTERED,
          width, height,
          SDL_WINDOW_SHOWN
  );

  SDL_Renderer *renderer = SDL_CreateRenderer(
          window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
  );

  for (;;) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    filledRect(renderer, 300, 200, 50, 50, 255, 0, 0, 128);
    SDL_RenderPresent(renderer); // Update screen.
  }
}