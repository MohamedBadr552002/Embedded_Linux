## Wire Shark install
1. update your local package software
```sh
sudo apt update
```
2. install wire shark
```sh
sudo apt install wireshark
```
3. Enter your username to wire shark
```sh
sudo usermod -aG wireshark "username"
```
4. Give Permission to dumpcap
```sh
sudo chmod +x /usr/bin/dumpcap
```
5.Then open Wire shark
```sh
sudo wireshark
```
6. choose the network you want to capture
![Screenshot from 2024-10-10 14-57-42](https://github.com/user-attachments/assets/f04897f8-a954-48ac-aaa8-2bc38b02897a)

7. Start Capture and Save .pacp file
![Screenshot from 2024-10-10 14-58-53](https://github.com/user-attachments/assets/24cea0e8-ac29-448d-8fbd-f4086941a532)


## Run bash Script on .pacp file

```sh
chmod +x network_analyzer.sh
```

```sh
./netwoek_analyzer  network_capture.pacp
```

![Screenshot from 2024-10-10 15-01-12](https://github.com/user-attachments/assets/ad9f4df7-e685-4c3b-a809-e0e8d8c30742)
