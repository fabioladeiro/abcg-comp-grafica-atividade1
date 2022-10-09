#include "window.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

void Window::onCreate() {
  auto const &windowSettings{getWindowSettings()};
  fmt::print("Initial window size: {}x{}\n", windowSettings.width,
             windowSettings.height);

  // fonte
  auto const filename{abcg::Application::getAssetsPath() +
                      "Inconsolata-Medium.ttf"};

  m_font = ImGui::GetIO().Fonts->AddFontFromFileTTF(filename.c_str(), 30.0f);
  if (m_font == nullptr) {
    throw abcg::RuntimeError{"Cannot load font file"};
  }

  restartGame();
}

void Window::restartGame() {
  // restarg game
  // o jogo é iniciado gerando um número aleatório de 1 a 6
  randomNumber = rand() % (6) + 1;
  // status do jogo no Play
  m_gameState = GameState::Play;
}

void Window::createGameButton(char buttonString, int numberButton) {
  // cria os botões com os números
  std::string text;
  text = fmt::format("{}", buttonString);

  if (ImGui::Button(text.c_str(), ImVec2(100, 50))) {
    // se ao clicar no botão o status for Play, é realizada a verificação
    // se o número do botão clicado estiver correto: WIN
    // se o número do botão clicado estiver errato: LOSE
    // só é possível jogar novamente ao clicar em Restart Game
    if (m_gameState == GameState::Play) {
      if (randomNumber == numberButton) {
        m_gameState = GameState::Win;
      } else {
        m_gameState = GameState::Lose;
      }
    } else {
      m_gameState = GameState::PlayAgain;
    }
  }
  ImGui::Spacing();
}

void Window::onPaintUI() {
  // Get size of application's window
  auto const appWindowWidth{gsl::narrow<float>(getWindowSettings().width)};
  auto const appWindowHeight{gsl::narrow<float>(getWindowSettings().height)};

  // "Adivinhe a cor" window
  ImGui::PushFont(m_font);

  {
    ImGui::SetNextWindowSize(ImVec2(appWindowWidth, appWindowHeight));
    ImGui::SetNextWindowPos(ImVec2(0, 0));

    auto const flags{ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoResize |
                     ImGuiWindowFlags_NoCollapse};
    ImGui::Begin("Adivinhe o número", nullptr, flags);

    // Menu
    // Menu inicial onde também é possível iniciar o Jogo
    {
      bool restartSelected{};
      if (ImGui::BeginMenuBar()) {
        if (ImGui::BeginMenu("Game")) {
          ImGui::MenuItem("Restart", nullptr, &restartSelected);
          ImGui::EndMenu();
        }
        ImGui::EndMenuBar();
      }
      if (restartSelected) {
        restartGame();
      }
    }

    // texto que mostra o status do jogo
    {
      std::string text;
      switch (m_gameState) {
      case GameState::Play:
        text = fmt::format("Vamos lá? Adivinhe o número!");
        break;
      case GameState::Lose:
        text = "iii, não foi dessa vez! Tente de novo!";
        break;
      case GameState::Win:
        text = "Na mosca!!";
        break;
      case GameState::PlayAgain:
        text = "Clique em Restart Game!";
        break;
      }

      // centralizando o texto
      ImGui::SetCursorPosX(
          (appWindowWidth - ImGui::CalcTextSize(text.c_str()).x) / 2);
      ImGui::Text("%s", text.c_str());
      ImGui::Spacing();
    }

    ImGui::Spacing();

    // BOTOES
    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{0.4f, 0.3f, 0.1f, 1.0f});
    ImGui::SetCursorPosX(appWindowWidth / 3);
    createGameButton('1', 1);

    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{0.2f, 0.3f, 0.4f, 1.0f});
    ImGui::SetCursorPosX(appWindowWidth / 2);
    createGameButton('2', 2);

    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{0.2f, 0.1f, 0.5f, 1.0f});
    ImGui::SetCursorPosX(appWindowWidth / 3);
    createGameButton('3', 3);

    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{0.9f, 0.3f, 0.9f, 1.0f});
    ImGui::SetCursorPosX(appWindowWidth / 2);
    createGameButton('4', 4);

    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{0.2f, 0.9f, 0.5f, 1.0f});
    ImGui::SetCursorPosX(appWindowWidth / 3);
    createGameButton('5', 5);

    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{0.4f, 0.4f, 0.4f, 1.0f});
    ImGui::SetCursorPosX(appWindowWidth / 2);
    createGameButton('6', 6);

    ImGui::PopStyleColor(6);

    // Botão "Restart game"

    {
      if (ImGui::Button("Restart game", ImVec2(-1, 50))) {
        restartGame();
      }
    }

    ImGui::End();

    ImGui::PopFont();
  }
}