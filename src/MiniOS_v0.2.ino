#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

#define BTN_UP 18
#define BTN_DOWN 19
#define BTN_SELECT 23

Adafruit_SSD1306 display(
  SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET
);

const char* menuItems[] = {
  "System Info",
  "Settings",
  "Apps",
  "About MiniOS"
};

const int MENU_COUNT = 4;
int selected = 0;

enum Screen {
  HOME,
  SYSTEM_INFO,
  SETTINGS,
  APPS,
  ABOUT
};

Screen currentScreen = HOME;

bool previousUp = HIGH;
bool previousDown = HIGH;
bool previousSelect = HIGH;

void drawHome() {
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);

  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("MINIOS v0.2");
  display.drawLine(0, 11, 127, 11, SSD1306_WHITE);

  for (int i = 0; i < MENU_COUNT; i++) {
    display.setCursor(4, 16 + i * 12);

    if (i == selected) {
      display.print(">");
    } else {
      display.print(" ");
    }

    display.println(menuItems[i]);
  }

  display.display();
}

void drawMessage(const char* title, const char* message) {
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);

  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println(title);
  display.drawLine(0, 11, 127, 11, SSD1306_WHITE);

  display.setCursor(0, 20);
  display.println(message);

  display.setCursor(0, 54);
  display.println("SELECT: Back");

  display.display();
}

void openSelected() {
  switch (selected) {
    case 0:
      currentScreen = SYSTEM_INFO;
      break;
    case 1:
      currentScreen = SETTINGS;
      break;
    case 2:
      currentScreen = APPS;
      break;
    case 3:
      currentScreen = ABOUT;
      break;
  }
}

void drawCurrentScreen() {
  switch (currentScreen) {
    case HOME:
      drawHome();
      break;
    case SYSTEM_INFO:
      drawMessage("SYSTEM INFO", "ESP32 DevKit V1\nMiniOS v0.2\nOLED: 128x64");
      break;
    case SETTINGS:
      drawMessage("SETTINGS", "More settings\ncoming soon!");
      break;
    case APPS:
      drawMessage("APPLICATIONS", "No apps installed\ncoming soon!");
      break;
    case ABOUT:
      drawMessage("ABOUT MINIOS", "Created by you!\nVersion 0.2");
      break;
  }
}

void setup() {
  pinMode(BTN_UP, INPUT_PULLUP);
  pinMode(BTN_DOWN, INPUT_PULLUP);
  pinMode(BTN_SELECT, INPUT_PULLUP);

  Wire.begin(21, 22);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (true) {}
  }

  drawCurrentScreen();
}

void loop() {
  bool up = digitalRead(BTN_UP);
  bool down = digitalRead(BTN_DOWN);
  bool select = digitalRead(BTN_SELECT);

  if (currentScreen == HOME) {
    if (previousUp == HIGH && up == LOW) {
      selected--;
      if (selected < 0) selected = MENU_COUNT - 1;
      drawHome();
    }

    if (previousDown == HIGH && down == LOW) {
      selected++;
      if (selected >= MENU_COUNT) selected = 0;
      drawHome();
    }

    if (previousSelect == HIGH && select == LOW) {
      openSelected();
      drawCurrentScreen();
    }
  } else {
    if (previousSelect == HIGH && select == LOW) {
      currentScreen = HOME;
      drawCurrentScreen();
    }
  }

  previousUp = up;
  previousDown = down;
  previousSelect = select;

  delay(35);
}
