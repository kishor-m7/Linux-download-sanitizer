from flask import Flask, request, jsonify
import yara
import subprocess
import datetime

app = Flask(__name__)

# Load YARA rules
rules = yara.compile(filepath="../rules/rules.yar")

LOG_FILE = "../logs/threat_log.txt"

def log_event(msg):
    with open(LOG_FILE, "a") as f:
        f.write(f"{datetime.datetime.now()} - {msg}\n")

#  YARA Scan
def scan_file(file_path):
    matches = rules.match(file_path)
    return len(matches) > 0

#  Kali Tool (Nmap)
def scan_ip(ip):
    try:
        result = subprocess.run(
            ["nmap", "-F", ip],
            capture_output=True,
            text=True
        )
        return result.stdout
    except:
        return "Scan failed"

#  API Endpoint
@app.route("/scan", methods=["POST"])
def scan():
    data = request.json
    file_path = data.get("file_path", "")
    ip = data.get("ip", "127.0.0.1")

    is_malicious = scan_file(file_path)

    if is_malicious:
        log_event(f" Malware detected in {file_path}")
        network_info = scan_ip(ip)

        return jsonify({
            "status": "malicious",
            "ip": ip,
            "network": network_info
        })
    else:
        log_event(f" Safe file: {file_path}")
        return jsonify({"status": "safe"})

if __name__ == "__main__":
    app.run(port=5000)