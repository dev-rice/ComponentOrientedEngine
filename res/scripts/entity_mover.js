var move_by = 0.001;
var border = 0.005;
var forward_direction = 1;
var backward_direction = 0

function isMovingForward() {
    return magic_number == forward_direction;
}

function isMovingBackward() {
    return magic_number == backward_direction;
}

function startToMoveForward() {
    magic_number = forward_direction;
}

function startToMoveBackward() {
    magic_number = backward_direction;
}

if (isMovingForward()) {
    transform2D.x += move_by;
    if (transform2D.x > border) {
        startToMoveBackward();
    }
} else if (isMovingBackward()){
    transform2D.x -= move_by;
    if (transform2D.x < -border) {
        startToMoveForward();
    }
}
