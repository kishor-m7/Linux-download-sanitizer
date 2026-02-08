# Linux Download Sanitizer

Lightweight scanner for downloaded files (YARA + helper scripts).

This repository contains extension and helper scripts used to scan downloaded files for suspicious content.

Contents
- `background.js`, `popup.js`, `popup.html` — extension UI and background logic
- `scanner.py` — Python scanning orchestration
- `pdf_utils.py`, `zip_utils.py`, `hash_utils.py`, `yara_utils.py` — helper modules
- `*.yar` — YARA rule sets used by the scanner

Usage
- Run the Python scanner locally: `python scanner.py`
- Inspect or extend YARA rules in the `*.yar` files

