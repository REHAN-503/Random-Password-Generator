# 🔐 PassGen — Secure Password Generator

A password generator with a **C binary** backend for entropy, **Node.js/Express** API layer, and a sleek **HTML frontend**.

## Architecture

```
Frontend (HTML/CSS/JS)
       ↓ fetch /api/generate
Node.js Express Server
       ↓ child_process.execFile
Native C Binary (passgen)
       ↓ stdout
Passwords returned as JSON
```

## Local Development

```bash
# Install dependencies
npm install

# Build C binary + start server
npm run dev
```

Open http://localhost:3000

## Deploy to Railway

### Option 1 — Railway CLI

```bash
npm install -g @railway/cli
railway login
railway init
railway up
```

### Option 2 — GitHub + Railway Dashboard

1. Push this repo to GitHub
2. Go to [railway.app](https://railway.app) → **New Project** → **Deploy from GitHub repo**
3. Select your repo — Railway auto-detects the `Dockerfile`
4. Click **Deploy** ✅

Railway will:
- Build the Docker image (installs gcc, compiles C, installs Node deps)
- Expose the app on a public HTTPS URL

## API

```
GET /api/generate?length=16&upper=true&digits=true&symbols=true&count=5
```

Response:
```json
{ "passwords": ["Xk9#mP2!qR7@nL4^", ...] }
```

## Features
- ✅ Native C binary for fast, low-level password generation
- ✅ Fisher-Yates shuffle for uniform distribution
- ✅ Guaranteed character set inclusion
- ✅ Configurable: length (4–128), charsets, count (1–20)
- ✅ Visual strength indicator
- ✅ One-click copy
- ✅ Railway-ready Dockerfile
