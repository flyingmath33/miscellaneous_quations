// unreliableJump is a function that move an object
// forward 1 step, 0 step or -1 step randomly.

class ReliableJump
{
public:
    int reliableJump()
    {
        int newPosition = position;
        while(newPosition == position + 1)
        {
            newPostion += unreliableJump();
        }
        position = newPosition;
        return position;
    }
private:
    int position;
};
