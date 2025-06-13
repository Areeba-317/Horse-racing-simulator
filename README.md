# Horse-racing-simulator
JJBA-named horses race through a chaotic, color-coded console track. One will win. Most will suffer.

A dramatic, colorful, and slightly chaotic console-based horse racing game written in C++.
Featuring iconic horse names inspired by JoJo's Bizarre Adventure (yes, I went there), this simulation includes:  

🎲 Random stats like speed, endurance, and fatigue  
🚧 Randomly placed obstacles (log fences, water trenches, zig-zag tracks, ditches)  
📉 Obstacle penalties that affect speed or fatigue dynamically  
🎨 ANSI color-coded race updates for immersion  
⏱️ Delays via Sleep() to create cinematic race progression  
👑 Automatically announces the winner in a dramatic, colored outro  

## How It Works  
1. Each of the 8 horses gets random speed and endurance.  
2. In each iteration of the race loop:  
 -> Their positions are updated based on their stats.  
 -> Fatigue is increased.  
 -> If they hit obstacles, they either lose speed or gain fatigue.  
3. Race continues until a horse crosses 150 units.  
4. The winner is announced   
