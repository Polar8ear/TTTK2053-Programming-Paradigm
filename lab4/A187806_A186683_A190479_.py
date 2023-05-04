"""
Created on March 2022 (rev. 2023)

@author: CHUO NGIU BING (A187806)
@author: LIM GUAN PENG (A186683)
@author: GOH JOEN KEN (A190479)
"""

import random
import turtle  # allows us to use the turtles library
import math
from typing import Dict, Literal

# For this lab task, we wrote several functions with parameter to adjust its position (x, y)
# and some has size/length to change its relative size to other drawings very easily.

# We have used some typing in the parameter of the functions so that we can autocomplete the function names😅

# Variables to change colors of different parts of the drawings easily
BACKGROUND_COLOR = "lightblue"
GROUND_COLOR = "green"
LEAF_COLOR = "chartreuse2"
TRUNK_COLOR = "brown"
SUN_COLOR = "orange"
CLOUD_COLOR = "#FAEBD7"



# A type for direction, only allow 4 directions
Direction = Literal["EAST", "SOUTH", "WEST", "NORTH"]


def set_turtle(t: turtle.Turtle, x=0, y=0, direction: Direction = "EAST"):
    """A utility function to reset the turtle, put it in a certain position, without drawing anything in the journey"""
    t.penup()
    t.setposition(x, y)
    DIRECTION_TO_HEADING: Dict[Direction, int] = {
        "EAST": 0,
        "NORTH": 90,
        "WEST": 180,
        "SOUTH": 270,
    }

    t.seth(DIRECTION_TO_HEADING[direction])
    t.pendown()
    t.color("black")


def draw_clouds(t: turtle.Turtle, x: int, y: int, size: int):
    def draw_circle(t: turtle.Turtle, size: int):
        t.fillcolor(CLOUD_COLOR)
        t.pencolor("")
        t.begin_fill()
        t.circle(size)
        t.end_fill()

    set_turtle(t, x, y)
    for _ in range(4):
        t.right(45)
        draw_circle(t, size)
        t.left(135)


def draw_bird(t: turtle.Turtle, x: int, y: int):
    t.pensize(4)
    set_turtle(t, x, y)
    t.right(-90)
    t.circle(15, extent=150)
    set_turtle(t, x, y, "NORTH")
    t.circle(-15, extent=150)
    set_turtle(t, x - 5, y)
    t.forward(10)
    t.pensize(1)


def draw_hill(t: turtle.Turtle, x: int, y: int, base_length: int):
    set_turtle(t, x - base_length / 2, y)
    slant = math.sqrt(base_length**2 / 2)
    t.fillcolor("#228B22")
    t.begin_fill()
    t.left(45)
    t.forward(slant)
    t.right(90)
    t.forward(slant)
    t.right(180 - 45)
    t.forward(base_length)
    t.end_fill()


def draw_tree(t: turtle.Turtle, x: int, y: int):
    def draw_trunk(t: turtle.Turtle, width: int, height: int, colour: str):
        t.fillcolor(colour)
        t.begin_fill()
        t.forward(width)
        t.left(90)
        t.forward(height)
        t.left(90)
        t.forward(width)
        t.left(90)
        t.forward(height)
        t.left(180)
        t.end_fill()

    set_turtle(t, x, y)
    draw_trunk(t, 15, 80, TRUNK_COLOR)

    def draw_leaf(t: turtle.Turtle, side_length: int, colour: str):
        t.fillcolor(colour)
        t.begin_fill()
        t.forward(side_length)
        t.left(135)
        t.forward(side_length / math.sqrt(2))
        t.left(90)
        t.forward(side_length / math.sqrt(2))
        t.left(135)
        t.end_fill()

    set_turtle(t, x - 35, y + 80)
    draw_leaf(t, 90, LEAF_COLOR)

    set_turtle(t, x - 35, y + 120)
    draw_leaf(t, 90, LEAF_COLOR)

    set_turtle(t, x - 35, y + 160)
    draw_leaf(t, 90, LEAF_COLOR)

    set_turtle(t, x - 35, y + 200)
    draw_leaf(t, 90, LEAF_COLOR)


def draw_ground(t: turtle.Turtle, y=0):
    screen_width = turtle.window_width()
    screen_height = turtle.window_height()
    set_turtle(t, -(screen_width / 2), y)
    t.color("", GROUND_COLOR)
    t.begin_fill()
    distances = (screen_width, screen_height // 2 + y) * 2
    for distance in distances:
        t.forward(distance)
        t.right(90)
    t.end_fill()


def draw_sun(t: turtle.Turtle, x=0, y=100, size=100):
    CORNER_DISTANCE = 10
    CORNER_COUNT = 12

    set_turtle(t, x, y - size / 2)
    t.color("", SUN_COLOR)
    t.begin_fill()
    t.circle(size / 2)
    t.end_fill()

    corner_radius = size // 2 + CORNER_DISTANCE
    corner_angle = 360 / CORNER_COUNT

    set_turtle(t, x, y + corner_radius)
    t.color("", SUN_COLOR)

    # go to starting position of corner
    t.circle(-corner_radius, -corner_angle / 2)

    for _ in range(CORNER_COUNT):
        t.begin_fill()
        t.circle(-corner_radius, corner_angle)  # draw the curve part
        current_angle = t.heading()
        t.right(
            180 + random.uniform((180 - corner_angle) / 4, (180 - corner_angle) / 2)
        )  # turn to the pointy end
        d = random.uniform(0.3, 0.4) * size
        t.forward(d)  # draw one side towards the pointy end
        t.end_fill()  # end_fill() to make it autocomplete from the point of begin_fill()
        t.backward(d)  # go back to the original position
        t.seth(current_angle)  # set the angle back to original angle


def main_draw():
    """Entry point to this module"""
    michelangelo = turtle.Turtle()  # Ninja😉
    michelangelo.speed(0)

    draw_sun(michelangelo, y=-100 + 50, size=100)

    draw_hill(michelangelo, -100, -100, 250)
    draw_hill(michelangelo, 230/2, -100, 250)

    draw_ground(michelangelo, -100)

    draw_clouds(michelangelo, 25, 150, 15)
    draw_clouds(michelangelo, 150, 150, 20)

    draw_bird(michelangelo, -200, 30)
    draw_bird(michelangelo, -220, 5)
    draw_bird(michelangelo, -265, 32)

    draw_tree(michelangelo, 200, -150)
    draw_tree(michelangelo, 175, -165)
    draw_tree(michelangelo, 250, -170)


    michelangelo.shape('turtle')
    set_turtle(michelangelo, -100, -100, "NORTH")
    michelangelo.shapesize(5, 5)
    michelangelo.color('black','green')


if __name__ == "__main__":
    # Overall turtle configuration
    turtle.bgcolor(BACKGROUND_COLOR)

    screen = turtle.Screen()
    screen.setup(800,450)
    screen.cv._rootwindow.resizable(False, False)
    main_draw()
    turtle.exitonclick()
