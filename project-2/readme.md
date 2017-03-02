## Project 2 - Internet Button

In this project, we'll use the Photon, a button, and Particle Event publishing to trigger internet actions.

#### Key Concepts/Components

- **Particle.publish():** Publishes an event to the internet within the Particle ecosystem. This is what we'll use with IFTTT to make the magic happen.

- **delay:** pause the program for the specified number of milliseconds, useful here so the button press is only registered once instead of as many times as the program loop cycles through while the button is pressed.

#### Component Layout

![button-led](https://cloud.githubusercontent.com/assets/1410181/23530465/04ecedac-ff5f-11e6-8871-b9ea5cee8b71.png)

#### Additional Steps

In order for this project to work, you'll need to set up an IFTTT "Applet".
- The "this" trigger in the "If this then that" flow needs to connect to your Particle account, and watch for the "New event published" action.
  - The "Event Name" should be `buttonPressed`.
  - You can leave "Event Contents" blank.
- Connect the "that" action to SMS and hook it up to your phone number.
