package main

import (
	"fmt"
	"net"
)

func main() {
	socketAddr := &net.UnixAddr{
		Name: "/tmp/UnixSock_Test",
		Net:  "unixgram",
	}

	conn, err := net.DialUnix(socketAddr.Net, nil, socketAddr)
	if err != nil {
		fmt.Printf("dail '%s' failed: %v\n", socketAddr.Name, err)
		return
	}
	defer conn.Close()

	if _, err := conn.Write([]byte("Hello!")); err != nil {
		fmt.Printf("send msg to '%s' failed: %v\n", socketAddr.Name, err)
		return
	}

	fmt.Println("send msg OK")
}
