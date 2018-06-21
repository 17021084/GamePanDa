#include "Menu.h"

bool checkMouse(SDL_Rect rect, int x, int y) {
	if (x >= rect.x && x <= rect.x + rect.w && y >= rect.y && y <= rect.y + rect.h)
		return true;
	return false;
}

bool createMenu(SDL_Renderer* ren, TTF_Font* font, SDL_Event event) {
	SDL_Texture* menu = loadTexture("panda/gamemenu.png", ren);
	renderTexture(menu, ren, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	
	text nameGame;
	nameGame.SetRect(230, 90);
	nameGame.SetText("Super Panda");
	nameGame.setColor(text::RED);
	nameGame.CreateText(ren, font);
	nameGame.render(ren);

	text item[NUM_ITEMS];
	item[0].SetRect(500, 300);
	item[0].setColor(text::PINK);
	item[0].SetText("Play");
	item[0].CreateText(ren, font);
	item[0].render(ren);

	item[1].SetRect(500, 450);
	item[1].setColor(text::PINK);
	item[1].SetText("Quit");
	item[1].CreateText(ren, font);
	item[1].render(ren);
	
	SDL_RenderPresent(ren);

	bool isRun = true;
	while (isRun) {
		
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				isRun = false;
				return false;
				break;

			case SDL_MOUSEMOTION:
				for (int i = 0; i < NUM_ITEMS; i++) {
					if (checkMouse(item[i].GetRect(), event.motion.x, event.motion.y)) {
						std::cout << checkMouse(item[i].GetRect(), event.motion.x, event.motion.y) << std::endl;
						item[i].setColor(text::ORANGE);
						item[i].CreateText(ren, font);
						item[i].render(ren);
					}
					else {
						std::cout << checkMouse(item[i].GetRect(), event.motion.x, event.motion.y) << std::endl;
						item[i].setColor(text::PINK);
						item[i].CreateText(ren, font);
						item[i].render(ren);
					}
					SDL_RenderPresent(ren);
				}
				break;

			case SDL_MOUSEBUTTONDOWN:
				if (checkMouse(item[0].GetRect(), event.motion.x, event.motion.y)) {
					isRun = false;
					return true;
				}
					
				if (checkMouse(item[1].GetRect(), event.motion.x, event.motion.y)) {
					isRun = false;
					return false;
				}
					
				break;
			}
			SDL_RenderPresent(ren);
		}
	}

	

}
void createGameOver(SDL_Renderer * ren, TTF_Font * font, std::string str, int HighScore)
{
	SDL_Texture* menu = loadTexture("panda/gameover.png", ren);
	renderTexture(menu, ren, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	text score;

	score.SetRect(420, 480);
	score.setColor(text::ORANGE);
	score.SetText(str);
	score.CreateText(ren, font);
	score.render(ren);

	text HScore;
	HScore.SetRect(300, 360);
	HScore.setColor(text::ORANGE);
	HScore.SetText("High Score: " + std::to_string(HighScore));
	HScore.CreateText(ren, font);
	HScore.render(ren);

	SDL_RenderPresent(ren);
	SDL_Delay(2000);
	SDL_DestroyTexture(menu);

}
