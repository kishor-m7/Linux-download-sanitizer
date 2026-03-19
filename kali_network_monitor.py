import subprocess

def scan_network():
    print("[+] Scanning network...")
    subprocess.run(["nmap", "-sn", "192.168.1.0/24"])

def capture_packets():
    print("[+] Capturing packets...")
    subprocess.run(["sudo", "timeout", "5", "tcpdump", "-i", "wlan0"])

if __name__ == "__main__":
    scan_network()
    capture_packets()