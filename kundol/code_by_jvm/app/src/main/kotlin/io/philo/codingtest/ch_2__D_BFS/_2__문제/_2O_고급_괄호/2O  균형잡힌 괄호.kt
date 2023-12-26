package io.philo.codingtest.ch_2__D_BFS._2__문제._2O_고급_괄호

import java.util.LinkedList

fun main() {

    while (true) {
        val input = readln()
        if (input == ".") break
        val replacedStr = input.replace(Regex("[a-zA-Z. ]"), "")

        val stack = LinkedList<String>()
        for (c in replacedStr) {
            val current = c.toString()
            if (stack.isEmpty()) {
                stack.push(current)
            } else {
                val last = stack.peek()
                if ((last == "(" && current == ")") || (last == "[" && current == "]")) {
                    stack.remove()
                } else {
                    stack.push(current)
                }
            }
        }

        var res = ""
        if(stack.isEmpty()) res="yes"
        else res="no"
        println(res)
    }
}