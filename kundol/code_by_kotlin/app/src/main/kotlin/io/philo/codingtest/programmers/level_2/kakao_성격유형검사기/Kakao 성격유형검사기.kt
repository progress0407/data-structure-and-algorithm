package io.philo.codingtest.programmers.level_2.kakao_성격유형검사기

// ["AN", "CF", "MJ", "RT", "NA"] -> TCMA
// ["TR", "RT", "TR"] -> RCJA
fun main() {

//    val res = solution(arrayOf("AN", "CF", "MJ", "RT", "NA"), intArrayOf(5, 3, 2, 7, 5))
    val res = solution(arrayOf("TR", "RT", "TR"), intArrayOf(7, 1, 3))
    println("res = $res")
}

/**
 * 비동의 ~ 동의
 *
 * 1 2 3 4 5 6 7
 *
 * R|T
 *
 * C|F
 *
 * J|M
 *
 * A|N
 */
private fun solution(surveys: Array<String>, choices: IntArray): String {

    val mbtiMap = mutableMapOf(Pair("RT", 0), Pair("CF", 0), Pair("JM", 0), Pair("AN", 0))
    var answer: String = ""
    val size = surveys.size

    for (i in 0..<size) {
        val survey = surveys[i]
        val choice = choices[i]

        val l = survey[0]
        val r = survey[1]
        var currentMbtiKey = ""

        for (entry in mbtiMap.entries) {
            val key = entry.key
            if (key.contains(l.toString())) {
                currentMbtiKey = key
                break
            }
        }

        if (choice == 4) {
            // do nothing
        } else {
            val currentPoint = mbtiMap[currentMbtiKey]
            if (currentMbtiKey[0] == l) {
                mbtiMap[currentMbtiKey] = currentPoint!! + (choice - 4)
            } else {
                mbtiMap[currentMbtiKey] = currentPoint!! + (4 - choice)
            }
        }
    }

//    println("mbtiMap = ${mbtiMap}")

    for (entry in mbtiMap) {

        val key = entry.key
        val value = entry.value
        val l = key[0]
        val r = key[1]

        if (value == 0) {
            answer += l
        } else if (value > 0) {
            answer += r
        } else {
            answer += l
        }
    }
    return answer
}
