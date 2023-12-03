import pathlib
from typing import Callable


def main():
    with open("input.txt") as file:
        motions = []
        for line in file:
            direction, distance = line.split()
            motions.append((direction, int(distance)))

    model_rope(motions, [(0, 0) for _ in range(2)])
    model_rope(motions, [(0, 0) for _ in range(10)])


def model_rope(motions: list[tuple[str, int]], rope: list[tuple[int, int]]):
    tail_positions = {rope[-1]}
    for motion in motions:
        direction, moves = motion

        if direction == "U":

            def next_pos(head: tuple[int, int]) -> tuple[int, int]:
                return (head[0] + 1, head[1])

        if direction == "D":

            def next_pos(head: tuple[int, int]) -> tuple[int, int]:
                return (head[0] - 1, head[1])

        if direction == "R":

            def next_pos(head: tuple[int, int]) -> tuple[int, int]:
                return (head[0], head[1] + 1)

        if direction == "L":

            def next_pos(head: tuple[int, int]) -> tuple[int, int]:
                return (head[0], head[1] - 1)

        move(rope, moves, next_pos, tail_positions)
    print(len(tail_positions))


def move(
    rope: list[tuple[int, int]],
    moves: int,
    next_pos: Callable[[tuple[int, int]], tuple[int, int]],
    tail_positions: set[tuple[int, int]],
):
    for _ in range(moves):
        rope[0] = next_pos(rope[0])
        for i in range(1, len(rope)):
            head, tail = rope[i - 1], rope[i]
            if distance(head, tail) > 1:
                # right
                if head[0] == tail[0] and head[1] > tail[1]:
                    tail = tail[0], tail[1] + 1
                # left
                elif head[0] == tail[0] and head[1] < tail[1]:
                    tail = tail[0], tail[1] - 1
                # up
                elif head[0] > tail[0] and head[1] == tail[1]:
                    tail = tail[0] + 1, tail[1]
                # down
                elif head[0] < tail[0] and head[1] == tail[1]:
                    tail = tail[0] - 1, tail[1]
                # up right
                elif head[0] > tail[0] and head[1] > tail[1]:
                    tail = tail[0] + 1, tail[1] + 1
                # up left
                elif head[0] > tail[0] and head[1] < tail[1]:
                    tail = tail[0] + 1, tail[1] - 1
                # down right
                elif head[0] < tail[0] and head[1] > tail[1]:
                    tail = tail[0] - 1, tail[1] + 1
                # down left
                elif head[0] < tail[0] and head[1] < tail[1]:
                    tail = tail[0] - 1, tail[1] - 1
                rope[i] = tail

        tail_positions.add(rope[-1])


def distance(head: tuple[int, int], tail: tuple[int, int]) -> int:
    x1, y1 = head
    x2, y2 = tail
    return max(abs(x2 - x1), abs(y2 - y1))


if __name__ == "__main__":
    main()