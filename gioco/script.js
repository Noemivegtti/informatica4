const game = document.getElementById("game");
const floor = document.getElementById("floor");
const character = document.getElementById("character");
const block = document.getElementById("block");
const portal = document.getElementById("portal");
const levelDisplay = document.getElementById("level");
const worldNameDisplay = document.getElementById("world-name");
const jumpsLeftDisplay = document.getElementById("jumps-left");
const gamePartDisplay = document.getElementById("game-part");
const trophiesDisplay = document.getElementById("trophies");
const gameOverScreen = document.getElementById("game-over");
const startScreen = document.getElementById("start-screen"); 
const startButton = document.getElementById("start-button"); 
const endTitle = document.getElementById("end-title");
const endText = document.getElementById("end-text");

// Stati Generali del Motore di Gioco
let currentPart = 1; 
let level = 1; 
let trophies = 0; 
let isAlive = true;
let gameStarted = false; 

// Parametri di calcolo dei frame
let jumpsTarget = 5; 
let jumpsDone = 0;
let levelCleared = false;
let blockLeft = 600;
let portalLeft = 600;
let currentSpeed = 4.5;
let blockWidth = 30; 
let blockHeight = 40; 
let blockPassed = false;

// Configurazione PARTE 1 (5 salti per livello)
const part1Config = {
    1: { name: "Minion", baseSpeed: 4.5, suffix: "minion", charVisual: "🟡", blockVisual: "🔪", minH: 35, maxH: 42, minW: 30, maxW: 35 },
    2: { name: "Fumogeno Nero", baseSpeed: 5.4, suffix: "fumogeno", charVisual: "💨", blockVisual: "⛽", minH: 38, maxH: 46, minW: 30, maxW: 35 },
    3: { name: "Postino Pat", baseSpeed: 6.2, suffix: "postino", charVisual: "✉️", blockVisual: "🏠", minH: 40, maxH: 50, minW: 30, maxW: 35 },
    4: { name: "Giudice Avvocato", baseSpeed: 7.0, suffix: "giudice", charVisual: "G", blockVisual: "🔨", minH: 40, maxH: 52, minW: 30, maxW: 35 },
    5: { name: "Scemo + Scemo", baseSpeed: 8.0, suffix: "scemo", charVisual: "🤪", blockVisual: "🚧", minH: 42, maxH: 55, minW: 34, maxW: 38 } 
};

// Configurazione PARTE 2 (10 salti per livello)
const part2Config = {
    1: { name: "Salva Gay", baseSpeed: 8.5, suffix: "salvagay", charVisual: "FLAG", blockVisual: "🍆", minH: 38, maxH: 50, minW: 30, maxW: 35 },
    2: { name: "Gnomo", baseSpeed: 9.2, suffix: "gnomo", charVisual: "🎅", blockVisual: "🍄", minH: 40, maxH: 55, minW: 30, maxW: 35 },
    3: { name: "Vacca", baseSpeed: 10.0, suffix: "vacca", charVisual: "🐄", blockVisual: "🌾", minH: 42, maxH: 58, minW: 30, maxW: 35 },
    4: { name: "Piccione", baseSpeed: 10.8, suffix: "piccione", charVisual: "🐦", blockVisual: "💈", minH: 45, maxH: 60, minW: 30, maxW: 35 },
    5: { name: "Cane", baseSpeed: 12.0, suffix: "cane", charVisual: "🐕", blockVisual: "🥣", minH: 45, maxH: 62, minW: 32, maxW: 36 }
};

function getCurrentConfig() {
    return currentPart === 1 ? part1Config[level] : part2Config[level];
}

function updateWorldTheme() {
    const config = getCurrentConfig();
    jumpsTarget = currentPart === 1 ? 5 : 10;
    
    gamePartDisplay.innerText = `PARTE ${currentPart}`;
    levelDisplay.innerText = level;
    worldNameDisplay.innerText = config.name;
    trophiesDisplay.innerText = trophies; 
    currentSpeed = config.baseSpeed;
    jumpsDone = 0;
    levelCleared = false;
    blockPassed = false;
    
    jumpsLeftDisplay.innerText = jumpsTarget - jumpsDone;

    game.className = ''; floor.className = ''; character.className = ''; block.className = '';
    
    game.classList.add(`sky-${config.suffix}`);
    floor.classList.add(`floor-${config.suffix}`);
    block.classList.add(`block-${config.suffix}`);

    block.innerText = config.blockVisual;

    let backgroundDuration = (15 / currentSpeed).toFixed(2);
    game.style.animationDuration = `${backgroundDuration}s`;

    if (config.charVisual === "FLAG") {
        character.innerText = ""; 
        character.classList.add("char-lgbt-style"); 
    } else if (config.charVisual === "G") {
        character.innerText = "G";
        character.classList.add("char-giudice-style"); 
    } else {
        character.innerText = config.charVisual; 
    }

    portal.style.display = "none";
    blockLeft = 600;
    portalLeft = 600;
}

function randomizeBlock() {
    const config = getCurrentConfig();
    blockHeight = Math.floor(Math.random() * (config.maxH - config.minH + 1)) + config.minH;
    blockWidth = Math.floor(Math.random() * (config.maxW - config.minW + 1)) + config.minW;

    block.style.height = blockHeight + "px";
    block.style.width = blockWidth + "px";
    block.style.fontSize = (blockHeight - 8) + "px"; 
    blockPassed = false;
}

function jump() {
    if (!character.classList.contains("jump") && isAlive && gameStarted) {
        character.classList.add("jump");
        setTimeout(() => { character.classList.remove("jump"); }, 520);
    }
}

startButton.addEventListener("click", function() {
    startScreen.style.display = "none"; 
    gameStarted = true;
    updateWorldTheme();
    randomizeBlock();
    gameLoop(); 
});

document.addEventListener("keydown", function(event) {
    if (event.code === "Space" && gameStarted) {
        if (isAlive) {
            jump();
        } else if (endTitle.innerText !== "VITTORIA FINALE COMPLETA!") {
            resetGame(); 
        }
    }
});

function gameLoop() {
    if (!isAlive || !gameStarted) return;

    if (!levelCleared) {
        blockLeft -= currentSpeed;
        
        if (blockLeft < 50 && !blockPassed) {
            blockPassed = true;
            jumpsDone++;
            jumpsLeftDisplay.innerText = jumpsTarget - jumpsDone;

            if (jumpsDone >= jumpsTarget) {
                levelCleared = true;
                portal.style.display = "block"; 
            }
        }

        if (blockLeft < -blockWidth) {
            blockLeft = 600;
            randomizeBlock();
        }
        block.style.left = blockLeft + "px";
        block.style.display = "flex";
    } else {
        block.style.display = "none";
        portalLeft -= currentSpeed;
        portal.style.left = portalLeft + "px";
    }

    const characterBottom = parseInt(window.getComputedStyle(character).getPropertyValue("bottom"));

    if (!levelCleared) {
        const isHitX = (blockLeft > 45 - blockWidth) && (blockLeft < 85);
        const isHitY = (characterBottom <= 20 + blockHeight);

        if (isHitX && isHitY) {
            isAlive = false;
            endTitle.innerText = "GAME OVER";
            endText.innerText = `Riprova il livello: ${getCurrentConfig().name}. Coppe: 🏆x${trophies}. Premi SPAZIO.`;
            gameOverScreen.style.display = "block";
            return;
        }
    } else {
        const isInPortalX = (portalLeft > 35) && (portalLeft < 85);
        if (isInPortalX) {
            if (level < 5) {
                trophies += 1; 
                level++;
                updateWorldTheme();
                randomizeBlock();
            } else {
                if (currentPart === 1) {
                    trophies += 10; 
                    currentPart = 2;
                    level = 1; 
                    updateWorldTheme();
                    randomizeBlock();
                } else {
                    trophies += 10; 
                    isAlive = false;
                    endTitle.innerText = "VITTORIA FINALE COMPLETA!";
                    endTitle.style.color = "#2ecc71";
                    endText.innerText = `Incredibile! Gioco finito con un totale di 🏆 x${trophies} Coppe!`;
                    gameOverScreen.style.display = "block";
                    return;
                }
            }
        }
        if (portalLeft < -50) portalLeft = 600;
    }

    requestAnimationFrame(gameLoop);
}

function resetGame() {
    isAlive = true;
    gameOverScreen.style.display = "none";
    updateWorldTheme();
    randomizeBlock();
    gameLoop();
}

updateWorldTheme();
randomizeBlock();
