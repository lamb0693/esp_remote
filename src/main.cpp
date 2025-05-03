#include <TFT_eSPI.h>
#include <XPT2046_Touchscreen.h>

#define TOUCH_CS  33
#define TOUCH_IRQ 36

TFT_eSPI tft = TFT_eSPI();
XPT2046_Touchscreen ts(TOUCH_CS, TOUCH_IRQ);

void setup() {
  Serial.begin(115200);
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_YELLOW, TFT_BLACK);
  tft.drawString("Hello, ILI9341!", 50, 50, 4);

  if (ts.begin()) {
    Serial.println("Touch ready");
  } else {
    Serial.println("Touch init failed");
  }
}

void loop() {
  if (ts.touched()) {
    TS_Point p = ts.getPoint();
    Serial.printf("Touch: x=%d y=%d\n", p.x, p.y);

    // 예: 화면 좌표 변환
    int tx = map(p.x, 0, 4095, 0, tft.width());
    int ty = map(p.y, 0, 4095, 0, tft.height());
    tft.fillCircle(tx, ty, 3, TFT_RED);
    delay(300);
  }
}
