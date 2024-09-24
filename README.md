<p align="center">
<img width="322" alt="ROSLogger" src="https://github.com/user-attachments/assets/174dcc90-0ee3-4cbe-aea7-8798d7ea554d" />
</p>

![Under Construction](https://img.shields.io/badge/status-under%20construction-orange?logo=vlcmediaplayer&logoColor=ffffff)
![Author](https://img.shields.io/badge/author-Manuel%20Eiter-blue)
![Using Unreal Engine](https://img.shields.io/badge/using-Unreal%20Engine-purple?logo=unrealengine)

![Using ROS2 Humble](https://img.shields.io/badge/using-ROS2%20Humble-green?logo=ros)
![Static Badge](https://img.shields.io/badge/Patiiiiiii-UNSAFE-red?logo=pipx&logoColor=red&logoSize=Auto)

---

# SeqLog Integration for ROS2UE5

**SeqLog** is an Unreal Engine 5 plugin designed to extend the functionality of the **ROS2UE5** repository by providing an interface to the Seq log data sink. It allows you to collect and retrieve detailed simulation data and log information from Cyber-Physical System (CPS) simulations, enhancing your ability to analyze and debug your robotic simulations.

## Table of Contents
- [Features](#features)
- [Requirements](#requirements)
- [Installation and Setup Guide](#installation-and-setup-guide)
  - [1. Install Seq (Datalust)](#1-install-seq-datalust)
  - [2. Add SeqLog Plugin to Your Unreal Project](#2-add-seqlog-plugin-to-your-unreal-project)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Features

- Logs and stores detailed simulation data from Unreal Engine and ROS2 in **Seq**, a centralized logging platform.
- Enables easy debugging and performance tracking of Cyber-Physical System simulations.
- Integrates seamlessly with the **ROS2UE5** plugin for advanced data analysis and monitoring.

## Requirements

To use the **SeqLog** plugin, you will need the following:

1. **Datalust Seq**: A centralized logging and analytics platform that allows for real-time monitoring of logs and metrics. The recommended way to install Seq is through its Docker container (see installation instructions below).
   
2. **Unreal Engine 5.3**: The SeqLog plugin is designed to work with projects built in Unreal Engine version 5.3 or higher.

3. **ROS2UE5 Plugin**: While the SeqLog plugin can be used on its own for logging purposes, it is most effective when used alongside the [ROS2UE5 plugin](https://github.com/ManuETR/ROS2UE5) for robotic simulations.

## Installation and Setup Guide

### 1. Install Seq (Datalust)

The easiest and most recommended way to install Seq is by using the Docker container provided by Datalust.

1. First, ensure Docker is installed on your system. You can find Docker installation instructions [here](https://docs.docker.com/get-docker/).

2. Run the following command to pull and run the official Seq Docker container:
   ```bash
   docker run --name seq -d --restart unless-stopped -e ACCEPT_EULA=Y -p 5341:80 datalust/seq
   ```

3. Once the container is up and running, Seq will be accessible at `http://localhost:5341`. You can open this URL in your browser to access the Seq dashboard.

4. Optionally, if you want to persist logs across container restarts, you can add a volume to the Docker run command:
   ```bash
   docker run --name seq -d --restart unless-stopped -e ACCEPT_EULA=Y -p 5341:80 -v /path/to/seq/log:/data datalust/seq
   ```

### 2. Add SeqLog Plugin to Your Unreal Project

1. Download or clone the **SeqLog** repository to your local machine:
   ```bash
   git clone https://github.com/ManuETR/SeqLog.git
   ```

2. Copy the `SeqLog` plugin folder into your Unreal project’s `Plugins` directory:
   ```
   <YourUnrealProject>/Plugins/SeqLog
   ```

3. Open your project in Unreal Engine and activate the **SeqLog** plugin:
   - Go to **Edit** -> **Plugins**.
   - Search for "SeqLog" and enable the plugin.
   - Restart Unreal Engine if prompted.

4. In Unreal Engine, navigate to the **SeqLog Settings** in the project settings:
   - **Edit** -> **Project Settings** -> **SeqLog**
   - Configure the Seq server URL (e.g., `http://localhost:5341`) to point to your running Seq instance.

## Usage

Once the plugin is set up and your project is running:

1. **Start Simulation**: Run your simulation in Unreal Engine as usual. SeqLog will automatically send log data to your Seq instance.

2. **Monitor Logs in Seq**: Open the Seq dashboard at `http://localhost:5341` to monitor real-time simulation data. You will be able to search, filter, and analyze logs from your simulation.

3. **Data Analysis**: Use the Seq query language (SQL-like) to search for specific log events, visualize data trends, and create alerts or dashboards for deeper insights into the performance and behavior of your simulation.

4. **Logging Custom Data**: You can also customize the logging behavior in Unreal Engine to send specific log messages or data points to Seq. See the Unreal Engine logging API for details on how to log custom events.

---
