#include <WiFi.h>

// Access Point settings
const char* ap_ssid = "Fake_AP";
const char* ap_password = "12345678";

//  Store received IP
String targetIP = "";

// Setup
void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);

  Serial.println("\n=== ESP32 Cyber Tool ===");
  showMenu();
}

// Main loop
void loop() {
  if (Serial.available()) {
    char choice = Serial.read();

    switch (choice) {
      case '1':
        scanWiFi();
        break;
      case '2':
        startFakeAP();
        break;
      case '3':
        receiveIP();
        break;
      case '4':
        Serial.println("Rebooting...");
        ESP.restart();
        break;
      default:
        Serial.println("Invalid option");
    }

    delay(1000);
    showMenu();
  }
}

//  Menu
void showMenu() {
  Serial.println("\nSelect Option:");
  Serial.println("1. Scan WiFi");
  Serial.println("2. Start Fake AP");
  Serial.println("3. Receive IP");
  Serial.println("4. Reboot");
}

// WiFi Scan
void scanWiFi() {
  Serial.println("\n[+] Scanning WiFi...");

  int n = WiFi.scanNetworks();

  if (n == 0) {
    Serial.println("No networks found");
  } else {
    for (int i = 0; i < n; i++) {
      Serial.print(i + 1);
      Serial.print(". ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" | RSSI: ");
      Serial.println(WiFi.RSSI(i));
    }
  }
}

//  Fake Access Point
void startFakeAP() {
  Serial.println("\n[+] Starting Fake AP...");

  WiFi.mode(WIFI_AP);
  WiFi.softAP(ap_ssid, ap_password);

  Serial.println("Fake AP Started");
  Serial.print("SSID: ");
  Serial.println(ap_ssid);
}

// Receive IP from Backend (Serial input)
void receiveIP() {
  Serial.println("\nEnter IP:");

  while (!Serial.available()) {
    delay(100);
  }

  targetIP = Serial.readStringUntil('\n');
  targetIP.trim();

  Serial.print("Received IP: ");
  Serial.println(targetIP);

  //  Simulate analysis
  Serial.println(" Analyzing target IP...");
  delay(1000);
  Serial.println(" Monitoring complete");
}