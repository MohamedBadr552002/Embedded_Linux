#!/bin/bash

# Bash Script to Analyze Network Traffic

# Input: Path to the Wireshark pcap file (provided as a command-line argument)
pcap_file="$1"

# Check if the pcap file was provided
if [ -z "$pcap_file" ]; then
    echo "Error: Please provide the path to a pcap file."
    echo "Usage: $0 <path_to_pcap_file>"
    exit 1
fi

# Check if the file exists
if [ ! -f "$pcap_file" ]; then
    echo "Error: File '$pcap_file' not found."
    exit 1
fi

# Function to extract information from the pcap file using tshark
analyze_traffic() {
    echo "Analyzing network traffic in $pcap_file..."

    # Total number of packets
    total_packets=$(tshark -r "$pcap_file" | wc -l)

    # HTTP packets
    http_packets=$(tshark -r "$pcap_file" -Y http | wc -l)

    # HTTPS/TLS packets
    https_packets=$(tshark -r "$pcap_file" -Y tls | wc -l)

    # Top 5 source IP addresses
    top_src_ips=$(tshark -r "$pcap_file" -T fields -e ip.src | sort | uniq -c | sort -nr | head -n 5)

    # Top 5 destination IP addresses
    top_dest_ips=$(tshark -r "$pcap_file" -T fields -e ip.dst | sort | uniq -c | sort -nr | head -n 5)

    # Output analysis summary
    echo "----- Network Traffic Analysis Report -----"
    echo "1. Total Packets: $total_packets"
    echo "2. Protocols:"
    echo "   - HTTP: $http_packets packets"
    echo "   - HTTPS/TLS: $https_packets packets"
    echo ""
    echo "3. Top 5 Source IP Addresses:"
    echo "$top_src_ips"
    echo ""
    echo "4. Top 5 Destination IP Addresses:"
    echo "$top_dest_ips"
    echo ""
    echo "----- End of Report -----"
}

# Run the analysis function
analyze_traffic
