## Project 3 - Internet Controlled LED

In this project, we'll define a Particle function which can be triggered from the internet (using IFTTT).

#### Key Concepts/Components

- **Particle.function("name", function) :** Lets you define a function that can be triggered from the internet. You pass in a `"name"` (used to trigger the function from the web) and a `function` (defines what function is called when this is triggered).

- **int setBrightness(String command) :** Defines a function when returns an `int` (integer). Functions that are registered with the `Particle.function` call must be of type `int`.

- **atoi(command) :** Converts a string to an integer. eg: atoi("42") returns the integer 42.

- **analogWrite:** Sends an analog signal (0 to 255) instead of a digital signal. Useful for controlling components which are not simply on/off, in this instance it controls the brightness of the LED.

- **`brightness` variable:** You'll notice that there's a `brightness` variable defined at the top of the file. Since it's defined outside of any function, it's available to all functions (it's a global variable). We'll use IFTTT to change this, and the loop will just display whatever the brightness is set to.

#### Component Layout

![button-led](https://cloud.githubusercontent.com/assets/1410181/23530465/04ecedac-ff5f-11e6-8871-b9ea5cee8b71.png)

#### Additional Steps

First, push the code for this project to the Photon, then set up another IFTTT Applet in order for this project to work.

- The "this" trigger will be SMS this time so you can send commands from your phone.
  - Choose "Send IFTTT any SMS"
- Connect the "that" action to Particle
  - Choose "Call a function"
  - The `setBrightness` function should be an option to choose from in IFTTT. If it's not make sure you've pushed the latest code and try again.
