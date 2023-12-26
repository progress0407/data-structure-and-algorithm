package io.philo.codingtest.utils

import java.util.LinkedList

/**
 * Stack 용도로 사용하려면 push
 * Queue 용도는 add
 *
 * pop은 가장 뒤의 원소를 뺀다 (시간 순이 아닌 공간 순서)
 */
fun main() {

//    val stack = LinkedList<Int>()
//    stack.push(1)
//    stack.push(2)
//    val last = stack.pop()
//    println("last = $last")
//    println("current stack = $stack")


    val stack = LinkedList<Int>()
    stack.push(1)
    stack.push(2)

    val last = stack.peek()
    println("last = $last")
    stack.remove()
    println("current stack = $stack")
}