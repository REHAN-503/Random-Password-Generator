FROM node:20-alpine

# Install gcc for compiling C code
RUN apk add --no-cache gcc musl-dev

WORKDIR /app

# Copy package files and install deps
COPY package*.json ./
RUN npm ci --production

# Copy source files
COPY src/ ./src/
COPY server.js ./
COPY public/ ./public/

# Compile the C password generator
RUN mkdir -p bin && gcc -O2 -o bin/passgen src/passgen.c

EXPOSE 3000
CMD ["node", "server.js"]
