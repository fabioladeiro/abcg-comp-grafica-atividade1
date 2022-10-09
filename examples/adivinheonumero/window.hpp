#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include "abcgOpenGL.hpp"

class Window : public abcg::OpenGLWindow {
protected:
  void onCreate() override;
  void onPaintUI() override;

private:
  ImFont *m_font{};

  // estados possíveis do jogo
  // Play: liberado para jogar
  // Win: acertou o número
  // Lose: errou o numero
  // PlayAgain: não consegue jogar de novo se não reiniciar
  enum class GameState { Play, Win, Lose, PlayAgain };
  GameState m_gameState;

  void restartGame();
  void createGameButton(char c, int b);

  int randomNumber;
};

#endif