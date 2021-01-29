
function getPathForTile(index) {

     var one = "qrc:/textures/one.png";
     var two = "qrc:/textures/two.png";
     var three = "qrc:/textures/three.png";
     var four = "qrc:/textures/four.png";
     var five = "qrc:/textures/five.png";
     var six = "qrc:/textures/six.png";
     var seven = "qrc:/textures/seven.png";
     var eight = "qrc:/textures/eight.png";
     var nine = "qrc:/textures/nine.png";
     var ten = "qrc:/textures/ten.png";
     var eleven = "qrc:/textures/eleven.png";
     var twelve = "qrc:/textures/twelve.png";
     var thirteen = "qrc:/textures/thirteen.png";
     var fourteen = "qrc:/textures/fourteen.png";
     var fiveteen = "qrc:/textures/fiveteen.png";

     switch (index)
     {
     case 1:
         return one;
     case 2:
         return two;
     case 3:
         return three;
     case 4:
         return four;
     case 5:
         return five;
     case 6:
         return six;
     case 7:
         return seven;
     case 8:
         return eight;
     case 9:
         return nine;
     case 10:
         return ten;
     case 11:
         return eleven;
     case 12:
         return twelve;
     case 13:
         return thirteen;
     case 14:
         return fourteen;
     case 15:
         return fiveteen;
     default:
         return {};
     }
}
