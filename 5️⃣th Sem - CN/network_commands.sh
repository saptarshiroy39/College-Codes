#!/bin/bash

# 1. Show IP address
ip a

# 2. Ping localhost
ping -c 4 127.0.0.1

# 3. Ping Google
ping -c 4 google.com

# 4. Show hostname
hostname

# 5. Show IP address (short format)
hostname -I

# 6. Show active listening ports
sudo ss -nltu

# 7. Manual for ss
man ss

# 8. Show active network connections (if netstat installed)
sudo netstat -antpl

# 9. Trace route to Google's DNS
traceroute 8.8.8.8

# 10. Network diagnostics
mtr google.com

# 11–13. Use dig for DNS info
dig google.com
dig google.com +noall +answer
dig google.com +short

# 14–16. Use nslookup for DNS info
nslookup google.com
nslookup -type=mx google.com
nslookup -type=ns google.com

# 17. Show ARP table
arp