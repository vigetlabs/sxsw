## Project 5 - Communicating Devices

In this project, we'll see how easy it is to make use of sensor readings.

#### Requirements

This project includes using multiple devices, so you'll need to grab a partner or two.

You'll notice that the code subscribes and publishes to the "sxsw-team-42" event. Your group will need to change the number (or the entire string) to something unique so that you're only responding to each other's published events.

Note 1: Your code will respond to your own published events if you've subscribed to the same event name that you're publishing to. If you'd like, publish and subscribe to different event names (as long as they inversely match up your partner's) so you only effect change on other devices.

#### Key Concepts/Components

- **Particle.subscribe("name", function) :** Subscribe to Particle events. You must pass in the `"name"` of the event, and a `function` to execute when the event is published.

- **Particle.publish("name", "data") :** Publish Particle events with specific data.

#### Component Layout
