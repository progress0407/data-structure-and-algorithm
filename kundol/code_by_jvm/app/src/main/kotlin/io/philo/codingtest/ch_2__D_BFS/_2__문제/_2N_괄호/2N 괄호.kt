package io.philo.codingtest.ch_2__D_BFS._2__문제._2N_괄호

import java.util.LinkedList

fun main() {

    val n = readln().toInt()

    repeat(n) {
        val str = readln()

        val stack = LinkedList<String>()
        for (ch in str) {
            val letter = ch.toString()
            if (stack.isEmpty()) {
                stack.push(letter)
            } else {
                val lastLetter = stack.peek()
                if (listOf(lastLetter, letter) == listOf("(", ")"))  {
                    stack.remove()
                }
                else {
                    stack.push(letter)
                }
            }
        }

        if(stack.isEmpty()) println("YES")
        else println("NO")
    }
}