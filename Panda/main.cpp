#include "common_function.h"
#include "ThreatObject.h"
#include "MainObject.h"
#include "text.h"
#include "Menu.h"

int main(int arc, char* argv[]) {

	//Creat background
	initSDL(window, renderer);
	background = loadTexture("panda/background.png", renderer);

	//Make audio
	test = Mix_LoadWAV("97.wav");
	bg = Mix_LoadWAV("background.wav");

	//Make Main Object
	MainObject panda;
	SDL_Texture* PandaLeft = loadTexture("panda/0.png", renderer);
	SDL_Texture* PandaRight = loadTexture("panda/1.png", renderer);
	SDL_Texture* PandaDie = loadTexture("panda/2.png", renderer);
	
	//Make Threat Objects
	SDL_Texture* SnailDie = loadTexture("snail/33.png", renderer);
	ThreatObject *snail = new ThreatObject[NUM_THREATS];

	for (int  i = 0; i < NUM_THREATS_UP; i++)
	{
		snail[i].SetTypeMove(ThreatObject::Up);
		snail[i].LoadImg(creatLinkImage(i, snail[i].GetTypeMove()), renderer);
		snail[i].setSpeed(SPEED);
		if (i % 2 == 0) {
			snail[i].SetTypeSnail(snail->Left);
		}
		else {
			snail[i].SetTypeSnail(snail->Right);
		}
	}

	for (int i = NUM_THREATS_UP; i < NUM_THREATS; i++)
	{
		snail[i].SetTypeMove(ThreatObject::Down);
		snail[i].LoadImg(creatLinkImage(i, snail[i].GetTypeMove()), renderer);
		snail[i].setSpeed(SPEED + 2);
		if (i % 2 == 0) {
			snail[i].SetTypeSnail(snail->Left);
		}
		else {
			snail[i].SetTypeSnail(snail->Right);
		}
	}

	//Make Type of Text
	smallText = TTF_OpenFont("Font/calamityJoe.ttf", 20);
	mediumText = TTF_OpenFont("Font/calamityJoe.ttf", 70);
	bigText = TTF_OpenFont("Font/calamityJoe.ttf", 100);

	//Make Score
	text score;
	score.SetText(score_str);
	score.SetRect(0, 0);
	score.setColor(text::ORANGE);
	score.CreateText(renderer, smallText);
	score.render(renderer);

	readHighScore(HighScore, "HighScore.txt");
	
	bool isRun = true;
	bool temp = createMenu(renderer, bigText, event);
	if (temp == false)
		isRun = false;
	while (isRun) {
		Mix_PlayChannel(-1, bg, 1);
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				isRun = false;
				break;
			}
			else
				panda.HandleInputAction(event, renderer);
		}		

		//Make Panda 
		panda.render(renderer);
		panda.HandMove();
		if (panda.GetType() == panda.Right) {
			panda.setObject(PandaRight);
		}
		else {
			panda.setObject(PandaLeft);
		}
		
		//Score
		score.render(renderer);

		SDL_RenderPresent(renderer);
		renderTexture(background, renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
		
		//Threats 	
		for (int i = 0; i < NUM_THREATS; i++)
		{
			if (snail[i].GetRect_y() <= 0 && snail[i].GetTypeMove() == ThreatObject::Up) {
				int x = randomBamboo(i);
				snail[i].setLoc(x);
				snail[i].SetRect(Snail_Loc[x], SCREEN_HEIGHT + i*100);
			}
			else if (snail[i].GetRect_y() >= SCREEN_HEIGHT && snail[i].GetTypeMove() == ThreatObject::Down) {
				int x = randomBamboo(i);
				snail[i].setLoc(x);
				snail[i].SetRect(Snail_Loc[x], i * -100);
			}
			snail[i].HandMove(SCREEN_WIDTH, SCREEN_HEIGHT);
			snail[i].render(renderer);

			//Check Conllision
			if (Collision(panda.GetRect(), snail[i].GetRect()) && panda.GetType() == snail[i].GetTypeSnail()) {
				if (panda.GetIs_attack() == false) {
					panda.removePanda(PandaDie, renderer, background);
					isRun = false;
				}
				else
				{
					snail[i].Remove(SnailDie, i);
					//Score plus
					score_val += 10;
					score_str ="Score: " + std::to_string(score_val);
					score.SetText(score_str);
					score.CreateText(renderer, smallText);
				}
				
			}
		}

		
	}
//	writeHighScore(score_val, HighScore, "HighScore.txt");
	std::ofstream file1;
	if (score_val >= HighScore) {
		file1.open("HighScore.txt");
		file1 << score_val;
		file1.close();
	}
	readHighScore(HighScore, "HighScore.txt");
	createGameOver(renderer, mediumText, score_str, HighScore);
	quitSDL(window, renderer);
	
	return 0;
}