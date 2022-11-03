package main

import (
	"fmt"
	"net"
	"os"
	"syscall"
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

	var ucred syscall.Ucred
	ucred.Pid = int32(os.Getpid())
	ucred.Uid = uint32(os.Getuid())
	ucred.Gid = uint32(os.Getgid())

	oob := syscall.UnixCredentials(&ucred)
	if _, _, err := conn.WriteMsgUnix(nil, oob, nil); err != nil {
		fmt.Printf("send msg to '%s' failed: %v\n", socketAddr.Name, err)
		return
	}

	fmt.Println("send msg OK")
}
