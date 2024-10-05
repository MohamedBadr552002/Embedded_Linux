#!/bin/bash

# Load configuration file
CONFIG_FILE="./process_monitor.conf"

if [ -f "$CONFIG_FILE" ]; then
  source "$CONFIG_FILE"
else
  echo "Configuration file not found. Using default settings."
  UPDATE_INTERVAL=5
  CPU_ALERT_THRESHOLD=90
  MEMORY_ALERT_THRESHOLD=80
fi

# Log file
LOG_FILE="./process_monitor.log"

# Function to list running processes
list_processes() {
  echo "Listing running processes..."
  ps -eo pid,comm,%cpu,%mem --sort=-%cpu
}

# Function to get detailed information about a specific process
process_info() {
  read -p "Enter PID: " pid
  if ps -p $pid > /dev/null; then
    ps -p $pid -o pid,ppid,user,%cpu,%mem,comm
  else
    echo "No process found with PID $pid."
  fi
}

# Function to kill a process
kill_process() {
  read -p "Enter PID to kill: " pid
  if kill -9 $pid 2>/dev/null; then
    echo "Process $pid killed successfully."
    echo "$(date) - Process $pid killed." >> "$LOG_FILE"
  else
    echo "Failed to kill process $pid."
  fi
}

# Function to display process statistics
process_stats() {
  echo "Total number of processes: $(ps aux | wc -l)"
  echo "Memory usage:"
  free -h
  echo "CPU load:"
  uptime
}

# Function for real-time monitoring
realtime_monitor() {
  while true; do
    clear
    list_processes
    sleep "$UPDATE_INTERVAL"
  done
}

# Function to search processes by name
search_process() {
  read -p "Enter process name to search: " name
  ps -eo pid,comm,%cpu,%mem --sort=-%cpu | grep "$name"
}

# Function for resource usage alerts
check_alerts() {
  ps -eo pid,comm,%cpu,%mem --sort=-%cpu | while read pid comm cpu mem; do
    if (( $(echo "$cpu > $CPU_ALERT_THRESHOLD" | bc -l) )); then
      echo "ALERT: Process $comm (PID: $pid) is using $cpu% CPU."
      echo "$(date) - ALERT: Process $comm (PID: $pid) is using $cpu% CPU." >> "$LOG_FILE"
    fi
    if (( $(echo "$mem > $MEMORY_ALERT_THRESHOLD" | bc -l) )); then
      echo "ALERT: Process $comm (PID: $pid) is using $mem% Memory."
      echo "$(date) - ALERT: Process $comm (PID: $pid) is using $mem% Memory." >> "$LOG_FILE"
    fi
  done
}

# Interactive menu for user options
interactive_menu() {
  while true; do
    echo "Process Monitor - Select an option:"
    echo "1) List running processes"
    echo "2) Get process information"
    echo "3) Kill a process"
    echo "4) Display process statistics"
    echo "5) Real-time monitoring"
    echo "6) Search processes by name"
    echo "7) Check resource usage alerts"
    echo "8) Exit"
    read -p "Enter your choice: " choice

    case $choice in
      1) list_processes ;;
      2) process_info ;;
      3) kill_process ;;
      4) process_stats ;;
      5) realtime_monitor ;;
      6) search_process ;;
      7) check_alerts ;;
      8) exit 0 ;;
      *) echo "Invalid option." ;;
    esac
  done
}

# Run interactive menu
interactive_menu

