package work

import (	
	"testing"
	"fmt"
)

type EchoTask string

func (s EchoTask) Run() {
	fmt.Println(s)
}

func TestWork(t *testing.T) {
	pool := New(1)
	pool.Add(EchoTask("hello world"))
	pool.Shutdown()
}
