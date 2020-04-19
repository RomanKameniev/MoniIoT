const five = require("johnny-five");

const { Board, Led, Button } = five;

const board = new Board();
const Oled = require("oled-js");

const pngparse = require("pngparse");
const pngtolcd = require("png-to-lcd");

board.on("ready", () => {
  const opts = {
    width: 128,
    height: 32,
    address: 0x3c,
  };

  const oled = new Oled(board, five, opts);
  // format: [x, y, color]
  //  oled.turnOnDisplay();
  oled.invertDisplay(true);
  pngtolcd("../photo/out_r.png", true, (err, bitmap) => {
    console.log("bitmap", bitmap);
  //  oled.drawBitmap(bitmap);
    oled.buffer = bitmap;
    oled.update();
  });

  // pngparse.parseFile("../photo/out_r.png", (err, image) => {
  //   if (err) console.log("err", err);

  //   oled.drawBitmap(image.data);
  // });
});
