# Game Design Document : Sheep With A Turret

S.W.A.T (Sheep With a Turret) is a side scrolling shooter game. The government has been secretly experimenting with sheep turrets.
Mr. Fluffles has escaped from a secret military facility out in the Hidden Omarian Valley. Your goal is to help Mr. Fluffles escape to
freedom!

#Controls:
+ A - Move Left
+ D - Move Right
+ Mouse Cursor - Rotate Turret.
+ Mouse Click - Shoot Missiles.

#Gameplay:
+ 3 Health Maximum.
+ +1 Health if Player shoot or touch a health box.
+ -1 Health if Player hit hamster.
+ -1 Health if Player hit bullet.
+ Move left and right on the screen to dodge bullets.
+ Use your mouse cursor to aim your turret.
+ Click mouse to fire turret.
+ Airplanes take 3 hits to kill.
+ Hamsters take 1 hit to kill.
+ Health boxes take 1 hit to absorb.
+ Each level has a different colored background.
+ Levels increase every 15 seconds.
+ Airplanes shoot more bullets every level.

#Scoring:
+ +25 pts. Shoot down airplanes (3 shots to kill).
+ +10 pts. Shoot a hamster (1 shot to kill).
+ -5 pts. per shot.
+ 1 pt. Every second.

## Objects:
### Player
+ Mr. Fluffles: Controlled by player.
  +  A - Left
  +  D - Right
  +  Mouse - Click to fire.
+ Health Bar
  + Shows the health of Mr. Fluffles.
  + Increases or decreases based on Mr. Fluffle's health.
  + If health = 0 then Mr. Fluffles "dies"
+ Mr. Fluffle's turret
  + Stationary turret on the back of Mr. Fluffles.
  + Weapons will shoot out of the turret's nozzle.
  + Weapon rotates to face mouse cursor.
+ Mr. Fluffle's missiles
  + A missile that fires from Mr. Fluffle's turret nozzle to the mouse point.
  + When a missile collides with an enemy, the missile will damage the enemy.

### Enemies
+ Missiles
 + Enemy aircrafts shoot missiles that fire on a random location on the ground.
 + Missiles will damage Mr. Fluffles and make him lose one bar of health.
 
+ Follow Missiles
 + Missiles that drop from a random location at the top of the screen towards the player's initial position when the missile is created.
 + Does 1 damage to the player if the player is hit by the missile.
 + Can only be dodged by the player.
 
+ Enemy Aircraft
 + Has 3 Health Points.
 + Shoots missiles at random locations on the ground.
 + As time goes on, aircrafts gain more missiles.
 + Aircrafts take damage from Mr. Fluffle's missiles.
 + Destroyed if hit 3 times by Mr. Fluffle's missiles.
 + Always spawns above the ground.
 + Not Damaged if sheep somehow manages to touch aircraft.

+ Deadly Hamsters
 + Has 1 hit point.
 + Only spawns on the right side of the screen on the ground.
 + Does not fire anything.
 + If hit sheep, sheep will lose one health bar.
 + If hit sheep, Deadly Hamster will disappear.
 + If Mr. Fluffle's missile hits Deadly Hamster, missile is destroyed.
 
### Other Items
+ Health Box
 + Falls downwards.
 + Oscillates horizontally left and right but does not go off screen horizontally.
 + Disappears if touches ground.
 + +1 health point to player if player shoots or touches the box.
+ Scrolling Background
 + Game object that provides a seemless transition for horizontally scrollable backgrounds.
 + Scrolls to the right only at a set speed.
+ Coin
 + Gives +100 extra points when collides with the player or player's bullets.
 + Follows the player.

### Buttons / User Interface
+ Start Button: Starts the game.
 + Changes to a Restart button if the player loses.
+ Pause Button: Pauses the game
+ Quit Button: Quits the game
+ Text Line: A place for users to put their name.
 + User's names will show up on the screen on the health bar located on the bottom of the game view.
 + Acceptable names include alpha-numeric characters excluding spaces up to 13 characters long.
 + Cannot be edited until the user quits the game once the game starts.
+ Text Box: Outputs any system messages from the game.

#Concept Art / ScreenShot
![alt text](Concept/pic.jpg "Concept Art")
![alt text](Concept/screenshot_01.png "Screenshot")
























