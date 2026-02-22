# 🔐 EntropyX — Quantum Credential Engine

A high-entropy credential generation system powered by a native **C randomness engine**, exposed through a **Node.js/Express API**, and delivered via a clean modern web interface.

🌍 **Live Application**  
https://entropyx-production.up.railway.app/

---

## 🚀 Overview

EntropyX is not a typical browser-based password generator.

Instead of relying on JavaScript’s `Math.random()`, it executes a compiled **C binary** to generate statistically uniform and high-entropy credentials.

This architecture ensures:
- Backend-level randomness
- Uniform distribution
- Fast native execution
- Stateless secure design

---

## 🧠 Core Principles

- Native entropy generation (C backend)
- Fisher–Yates shuffle for uniform randomness
- Guaranteed character distribution
- Strict input validation
- No password storage
- No logging of generated secrets
- Stateless API

---

## 🏗 Architecture

```
Frontend (HTML / CSS / JS)
        ↓ fetch('/api/generate')
Node.js Express Server
        ↓ child_process.execFile()
Native C Binary (entropyx)
        ↓ stdout
JSON Response → UI
```

### 🔎 Flow

1. User selects generation parameters.
2. Frontend sends GET request to `/api/generate`.
3. Express validates parameters.
4. Server executes compiled C binary.
5. Passwords are generated in C.
6. Output returned as JSON.
7. UI renders credentials instantly.

---

## ✨ Features

### 🔐 Security
- Native C entropy engine
- Fisher–Yates shuffle
- Stateless computation service
- No database
- No session tracking
- No credential persistence
- Server-side validation

### ⚙️ Customization
- Length: **4–128 characters**
- Character sets:
  - Lowercase (a–z)
  - Uppercase (A–Z)
  - Digits (0–9)
  - Symbols (!@#$%^&*)
- Generate **1–20 credentials per request**

### 🎨 UI
- Clean responsive interface
- Multiple credential generation
- One-click copy
- Lightweight frontend
- Fast rendering

---

## 📡 API Documentation

### Endpoint

```
GET /api/generate
```

### Query Parameters

| Parameter | Type | Range | Description |
|-----------|------|--------|------------|
| length | number | 4–128 | Credential length |
| lower | boolean | true/false | Include lowercase |
| upper | boolean | true/false | Include uppercase |
| digits | boolean | true/false | Include numbers |
| symbols | boolean | true/false | Include symbols |
| count | number | 1–20 | Number of credentials |

---

### Example Request

```
/api/generate?length=16&lower=true&upper=true&digits=true&symbols=true&count=3
```

### Example Response

```json
{
  "passwords": [
    "Xk9#mP2!qR7@nL4^",
    "aT8$zP4!Lm2@Qr6#",
    "N8@xP3!kLm7#Rt5$"
  ]
}
```

---

## 🛠 Local Development

### 1️⃣ Install Dependencies

```
npm install
```

### 2️⃣ Build C Binary + Start Server

```
npm run dev
```

Open:

```
http://localhost:3000
```

---

## 🐳 Docker Deployment

### Build Image

```
docker build -t entropyx .
```

### Run Container

```
docker run -p 3000:3000 entropyx
```

---

## 🚂 Deploy to Railway

### Option 1 — Railway CLI

```
npm install -g @railway/cli
railway login
railway init
railway up
```

### Option 2 — GitHub + Railway Dashboard

1. Push repo to GitHub
2. Go to https://railway.app
3. Click **New Project**
4. Select **Deploy from GitHub**
5. Choose repository
6. Deploy

Railway automatically:
- Installs GCC
- Compiles C binary
- Installs Node dependencies
- Builds Docker image
- Exposes HTTPS URL

---

## 📁 Project Structure

```
entropyx/
│
├── public/        # Frontend UI
├── entropyx.c     # Native entropy engine
├── server.js      # Express API
├── Dockerfile
├── package.json
└── README.md
```

---

## 🛡 Security Model

- No credential storage
- No logging
- No database
- No external API calls
- Isolated execution via execFile
- Strict parameter validation

EntropyX acts as a pure computation engine.

---

## 🧬 Why “Quantum”?

“Quantum” symbolizes unpredictability and non-deterministic behavior — representing high entropy and statistical randomness.

This project does not use quantum computing, but reflects the unpredictability philosophy behind its design.

---

## 🔮 Future Roadmap

- Entropy bits calculator
- Diceware passphrase mode
- Rate limiting
- WebAssembly build
- CLI standalone version
- Dark mode UI

---

## 🧑‍💻 Tech Stack

- C (Entropy Engine)
- Node.js
- Express.js
- HTML5
- CSS3
- Vanilla JavaScript
- Docker
- Railway

---

## 📜 License

MIT License

---

Built with low-level performance + modern web architecture.
