# MCSH-Class

#### 課程: ESP32 實作業師課程
#### 時間: 3/2 3/16 3/23 4/6 4/20 4/27週二 13：10-14：50
#### 材料: [清單](https://github.com/jumbokh/MCSH-Class/blob/main/%E6%98%8E%E8%AA%A0%E4%B8%AD%E5%AD%B8%E5%AF%A6%E7%BF%92%E6%9D%90%E6%96%99%E9%9C%80%E6%B1%82%E8%A1%A8-%E7%89%A9%E8%81%AF%E7%B6%B2Arduino.doc)
##
### Outline
<pre>
1. 簡易電子電路及開發環境介紹+學習單（學習單方便用來學習歷程認證）
   使用 Arduino IDE, Thonny, Google Colab
2. 數位輸出輸入, 使用 LED, Button, Dip Switch, Buzzer
3. 類比及感測器輸入, 旋轉可變電阻, 光敏電阻, DHT11 溫溼度感測器
4. 手機藍芽控制, 繼電器使用, 手機語音控制, USB風扇 or LED 
5. 步頻計數器訓練及測試
6. MQTT 介紹, 雲端數據分析, 中華電信平台接受溫濕度數據
7. LASS 平台介紹及本地溫溼度資料上傳
8. Line 權杖申請及資料傳送
9. 聲音感測器及語音訓練
</pre>
##
#### Reference
* [my ref. 1](https://github.com/jumbokh/esp32-class)
* [my ref. 2](https://youyouyou.pixnet.net/blog/post/119410732?pixfrom=related)
* [esp32 getting started](https://randomnerdtutorials.com/getting-started-with-esp32/)
* [DOIT board](https://idyl.io/doit-esp32-development-board-review/)
* [esp32 buzzer](https://diyi0t.com/active-passive-buzzer-arduino-esp8266-esp32/)
* [buzzer](https://techtutorialsx.com/2017/07/01/esp32-arduino-controlling-a-buzzer-with-pwm/)
* [tone](https://www.arduino.cc/en/Tutorial/BuiltInExamples/toneMelody)
* [rc](https://atommann.github.io/learn/rc-circuit/rc-circuit.html)
* [IFTTT](https://youyouyou.pixnet.net/blog/post/119623728)
* [紅外線](https://openhome.cc/Gossip/CodeData/mBlockArduino/mBlockArduino11.html)

##
* ![DOIT ESP32](https://github.com/jumbokh/MCSH-Class/blob/main/images/ESP32-DOIT-DEVKIT-V1-Board-Pinout-30-GPIOs-Copy.png)
#### Lab
* Lab1 數位輸出      Buildin LED, GPIO13 LED, Time Delay
    * ![led](https://github.com/jumbokh/MCSH-Class/blob/main/LAB/Lab1LED/esp32-led_bb.jpg)
    * [LED Build IN](https://github.com/jumbokh/MCSH-Class/blob/main/LAB/Lab1LED/Blink_builtin.ino)
    * ![2led](https://github.com/jumbokh/MCSH-Class/blob/main/LAB/Lab1LED/esp32-2led_bb.jpg)
    * [LED Flash](https://github.com/jumbokh/MCSH-Class/blob/main/LAB/Lab1LED/LED_Flash/LED_Flash.ino)
    
* Lab2 數位輸入      按鈕讀取, 解決彈跳問題, 按鈕切換LED亮滅
    * ![btn](https://github.com/jumbokh/MCSH-Class/blob/main/LAB/Lab2Button/esp32-btnled.jpg)
    * [按鈕](https://github.com/jumbokh/MCSH-Class/blob/main/LAB/Lab2Button/Button/Button.ino)
    * [LED切換](https://github.com/jumbokh/MCSH-Class/blob/main/LAB/Lab2Button/StateChangeDetection/StateChangeDetection.ino)
    * [解決彈跳](https://github.com/jumbokh/MCSH-Class/blob/main/LAB/Lab2Button/Debounce.ino)
    * [彈跳 py](https://github.com/jumbokh/esp32-class/blob/master/hs1227/bump.py)
    * ![bump](https://github.com/jumbokh/esp32-class/blob/master/images/bumping.png)
* Lab3 呼吸的燈      PWM介紹
    * [呼吸燈](https://github.com/jumbokh/MCSH-Class/blob/main/LAB/Lab3PWM/LED_PWM_Example_1/LED_PWM_Example_1.ino)
* Lab4 指撥開關
    * ![dip sw](https://github.com/jumbokh/MCSH-Class/blob/main/LAB/Lab4DipSwitch/esp32-dip_bb.jpg)
    * [2dip](https://github.com/jumbokh/MCSH-Class/blob/main/LAB/Lab4DipSwitch/Digitaldipsw/Digitaldipsw.ino)
    * [sw py](https://github.com/jumbokh/esp32-class/blob/master/hs1227/switch-led.py)
    * [refer](http://blog.ilc.edu.tw/blog/index.php?op=printView&articleId=656348&blogId=868)
* Lab5 類比輸入
    * ![vr](https://github.com/jumbokh/MCSH-Class/blob/main/images/esp32-vr_bb.jpg)
    * [AnalogIn](https://github.com/jumbokh/MCSH-Class/blob/main/LAB/Lab5Analog/analogIn/analogIn.ino)
    * [AnalogInOutSerial](https://github.com/jumbokh/MCSH-Class/blob/main/LAB/Lab7AnalogInOutSerial/Lab7AnalogInOutSerial.ino)
    * [超簡易控制RGB燈條](https://www.youtube.com/watch?v=VLKr5pDQ_rU)
* Lab6 蜂鳴器        救護車, 小星星
    * ![buzzer pinout](https://github.com/jumbokh/MCSH-Class/blob/main/images/esp32-buzzer_bb.jpg) 
#### Add Library from zip: [Tone32](https://github.com/lbernstone/Tone32)
* [ESP32 Tone](https://github.com/jumbokh/MCSH-Class/blob/main/LAB/Lab6ESP32Tone/Lab6ESP32Tone.ino)
* [ESP32 Alert](https://github.com/jumbokh/MCSH-Class/blob/main/LAB/Lab6-1Buzzer-Alert/Lab6-1Buzzer-Alert.ino)
* [ESP32 Bee](https://github.com/jumbokh/esp32-class/blob/master/hs1206/src/Buzzer-bee/Buzzer-bee.ino)
##
#### 小星星簡譜
* ![小星星簡譜](https://github.com/jumbokh/esp32-class/blob/master/images/%E5%B0%8F%E6%98%9F%E6%98%9F%E7%B0%A1%E8%AD%9C.png)
##
* Lab7 光敏電阻
    * 分壓電路
    * ![Rdiv](https://github.com/jumbokh/MCSH-Class/blob/main/images/Rdiv.JPG)
    * ![photoresistor](https://github.com/jumbokh/MCSH-Class/blob/main/LAB/esp32-photo_bb.jpg)
    * [AnalogInOutSerial](https://github.com/jumbokh/MCSH-Class/blob/main/LAB/Lab7AnalogInOutSerial/Lab7AnalogInOutSerial.ino)
* Lab8 RC 電路實驗
    * ![RC](https://github.com/jumbokh/MCSH-Class/blob/main/images/RC3v3R10kC2200u_bb.jpg)
    * [RCex](https://github.com/jumbokh/MCSH-Class/blob/main/LAB/Lab8-0RCex/Lab8-0RCex.ino)
##
### Let V(t) = Vo* e^{-t/RC}
##
### 步驟 1. 執行, 打開串列埠監視視窗, RESET, 按鈕開始充電
### 步驟 2. 從監視視窗複製資料, 貼到文字檔, 儲存為 xxx.csv
### 步驟 3. 新增 Excel 檔,複製 xxx.csv 的資料到第三欄 
<pre>
Title: 
                                 No.  Calculate   Run
                                  0    0          0
                                  ...
</pre>
#### 公式:
<pre>
=3.3*(1-EXP(1)^(-A2/(10000*0.0022)))
</pre>
### 步驟 4. 插入折線圖
* ![RC](https://github.com/jumbokh/MCSH-Class/blob/main/images/RC3v3.JPG)
### 步驟 5. 修改程式, 將資料添加到陣列
* [Sendout](https://github.com/jumbokh/MCSH-Class/blob/main/LAB/Lab8-1RCSend/Lab8-1RCSend.ino)
##
* Lab 9 WiFi 連接
* Lab9-1 [WiFi scan](https://github.com/jumbokh/MCSH-Class/blob/main/LAB/Lab9-1wifi_scan/Lab9-1wifi_scan.ino)
* Lab9-2 [SimpleWiFiServer](https://github.com/jumbokh/MCSH-Class/blob/main/LAB/Lab9-2SimpleWiFiServer/Lab9-2SimpleWiFiServer.ino)
* Lab9-3 [Cloud Data Logger](https://github.com/jumbokh/MCSH-Class/blob/main/LAB/Lab9-3cloud_data_logger/Lab9-3cloud_data_logger.ino)
* Lab9-4 [Data to Google Sheets]()
### [iFTTT 講義](https://github.com/jumbokh/MCSH-Class/blob/main/docs/ESP32-iFTTT.pptx)
### iFTTT: https://ifttt.com/home
* 參考 [夜市小霸王: 尤老師介紹如何將資料送至 Google Documents](https://youyouyou.pixnet.net/blog/post/119623728)
##
* Lab9 DHT11 溫溼度感測器
    * [ESP32 DHT11](https://youyouyou.pixnet.net/blog/post/120275893-%E7%AC%AC%E4%B9%9D%E7%AF%87-esp32-%E6%BA%AB%E6%BF%95%E5%BA%A6%E9%A1%AF%E7%A4%BA%E5%99%A8%28dht11%2B1602-lcd%29)
* Lab10 LCD1602       字串顯示
    * [LCD1602](https://github.com/jumbokh/esp32-class/blob/master/arduino0920/README.md)
##
* Lab11 繼電器
* Lab12 超音波感測器   電子尺
* Lab13 藍芽控制
* Lab14 手機控制藍芽 LED
* Lab15 手機控制藍芽+風扇(或牙刷型USB燈)
* Lab16 [步頻計數器](https://github.com/jumbokh/esp32-class/tree/master/Lab-walk)
* Lab17 麥克風實驗
    * https://diyi0t.com/sound-sensor-arduino-esp8266-esp32/
##
