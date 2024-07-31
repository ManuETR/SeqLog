<p align="center">
<img width="322" alt="ROSLogger" src="https://github.com/user-attachments/assets/cfde7eb6-18ee-4ee3-9ae1-f8cdecf5e8b8" />
</p>

# ROSLogger
![Under Construction](https://img.shields.io/badge/status-under%20construction-orange?logo=vlcmediaplayer&logoColor=ffffff)
![Author](https://img.shields.io/badge/author-Manuel%20Eiter-blue)
![Using Unreal Engine](https://img.shields.io/badge/using-Unreal%20Engine-purple?logo=unrealengine)
![Using ROS2 Humble](https://img.shields.io/badge/using-ROS2%20Humble-green?logo=ros)
![Static Badge](https://img.shields.io/badge/Patiiiiiii-UNSAFE-red?logo=pipx&logoColor=red&logoSize=Auto)

## Overview

ROSLogger is an Unreal Engine 5.3 plugin designed to log ROS2 messages by fetching them from rosbridge and forwarding them to the internal Unreal Engine log. It allows users to specify which topics and nodes to listen to, facilitating seamless integration of ROS2 systems with Unreal Engine projects.

## Features

- Fetch ROS2 messages from rosbridge
- Log ROS2 messages to Unreal Engine internal log
- Specify topics and nodes to listen to
- Easy integration with Unreal Engine 5.3 projects

## Prerequisites

- Unreal Engine 5.3
- ROS2 Humble

## Installation

### ROS2 and rosbridge_suite

Ensure you have ROS2 Humble and rosbridge_suite installed and running:

1. Install ROS2 Humble: [ROS2 Installation Guide](https://docs.ros.org/en/humble/Installation.html)
2. Install rosbridge_suite:
    ```bash
    sudo apt update
    sudo apt install ros-humble-rosbridge-suite
    ```
3. Run rosbridge:
    ```bash
    ros2 launch rosbridge_server rosbridge_websocket_launch.xml
    ```

### Plugin Installation

1. Clone this repository into your Unreal Engine project's `Plugins` directory:
    ```bash
    cd YourUnrealProject/Plugins
    git clone https://github.com/yourusername/ROSLogger.git
    ```

2. Open your Unreal Engine project and navigate to the `Plugins` menu. Enable the "ROSLogger" plugin and restart the editor if prompted.

## Usage

### Configuration

1. Open the Unreal Engine project settings and navigate to `Plugins > ROSLogger`.
2. Configure the connection settings for rosbridge:
    - **WebSocket Address**: The WebSocket address of your rosbridge server (e.g., `ws://localhost:9090`).
    - **Topics**: List the ROS2 topics you want to listen to.
    - **Nodes**: List the ROS2 nodes you want to listen to (optional).

### Example

Here's an example configuration:

- **WebSocket Address**: `ws://localhost:9090`
- **Topics**:
    - `/example_topic1`
    - `/example_topic2`
- **Nodes** (optional):
    - `/example_node1`

### Logging

ROS2 messages from the specified topics and nodes will be logged to the Unreal Engine internal log. You can view the log messages in the Output Log window within the Unreal Engine editor.

## Contributing

Contributions are welcome! Please open an issue or submit a pull request with any improvements or bug fixes.
