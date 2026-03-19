Overview:
This project is a hybrid cybersecurity system that combines hardware and software to detect and analyze cyber threats. It uses an ESP32-based device to simulate attacks and a Python backend to detect malicious files and monitor network activity.
Features:
ESP32-based attack simulation (WiFi scan, Fake AP)

 YARA-based malware detection

 Network analysis using Kali Linux tools (Nmap, tcpdump)

 Real-time alerts via browser extension

 Threat logging system
 Working flow:
 ESP32 simulates network attack

User downloads a file

Extension detects download

File sent to backend (Flask API)

YARA scans file for malware

If malicious:

Logs threat

Runs network scan (Nmap)

Sends alert

Displays result to user
Installation:
Install Kali tools

sudo apt install nmap tcpdump -y