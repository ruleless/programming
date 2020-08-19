// work使用一个goroutine池来完成工作

package work

import (
	"sync"
)

type Task interface {
	Run()
}

type Pool struct {
	tasks chan Task
	wg    sync.WaitGroup
}

func New(workerCount int) *Pool {
	pool := &Pool{
		tasks: make(chan Task),
	}
	
	pool.wg.Add(workerCount)

	for i := 0; i < workerCount; i++ {
		go func() {
			for t := range pool.tasks {
				t.Run()
			}

			pool.wg.Done()
		}()
	}

	return pool
}

func (p *Pool) Add(t Task) {
	p.tasks <- t
}

func (p *Pool) Shutdown() {
	close(p.tasks)
	p.wg.Wait()
}
