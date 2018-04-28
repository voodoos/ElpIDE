/* In this file we describe the various enumerations needed to build bindings. The [@bs.deriving jsConverter]
 * annotation will make bs generate enumnameToJs function for us. These are used in the Sui_tools module */
[@bs.deriving jsConverter]
type color = [
  | `red
  | `orange
  | `yellow
  | `olive
  | `green
  | `teal
  | `blue
  | `violet
  | `purple
  | `pink
  | `brown
  | `grey
  | `black
  | `facebook
  | [@bs.as "google plus"] `googleplus
  | `instagram
  | `linkedin
  | `twitter
  | `vk
  | `youtube
];

[@bs.deriving jsConverter]
type size = [
  | `mini
  | `tiny
  | `small
  | `medium
  | `large
  | `big
  | `huge
  | `massive
];

[@bs.deriving jsConverter]
type sizeHeader = [ | `tiny | `small | `medium | `large | `huge];

[@bs.deriving jsConverter]
type sizePopup = [ | `mini | `tiny | `small | `large | `huge];

[@bs.deriving jsConverter]
type sizeModal = [ | `fullscreen | `large | `small | `mini | `tiny];

[@bs.deriving jsConverter]
type pos = [
  | [@bs.as "top left"] `topleft
  | [@bs.as "top right"] `topright
  | [@bs.as "bottom right"] `bottomright
  | [@bs.as "bottom left"] `bottomleft
  | [@bs.as "right center"] `rightcenter
  | [@bs.as "left center"] `leftcenter
  | [@bs.as "top center"] `topcenter
  | [@bs.as "bottom center"] `bottomcenter
];

[@bs.deriving jsConverter]
type labelPos = [
  | [@bs.as "left"] `left
  | [@bs.as "right"] `right
  | [@bs.as "right corner"] `rightcorner
  | [@bs.as "left corner"] `leftcorner
];

[@bs.deriving jsConverter]
type smallOrLarge = [ | `small | `large];

[@bs.deriving jsConverter]
type allDir = [ | `left | `right | `top | `bottom];

[@bs.deriving jsConverter]
type leftOrRight = [ | `left | `right];

[@bs.deriving jsConverter]
type leftOrCenterOrRight = [ | `left | `center | `right];

[@bs.deriving jsConverter]
type textAlign = [ | `left | `center | `right | `justified];

[@bs.deriving jsConverter]
type topOrBottom = [ | `top | `bottom];

[@bs.deriving jsConverter]
type topOrMiddleOrBottom = [ | `top | `middle | `bottom];

[@bs.deriving jsConverter]
type animButton = [ | `fade | `vertical];

/*| `1 | `2 | `3 | `4 | `5 | `6 | `7 | `8 | `9 | `10 | `11 | `12 | `13 | `14 | `15 | `16*/
[@bs.deriving jsConverter]
type width = [
  | `one
  | `two
  | `three
  | `four
  | `five
  | `six
  | `seven
  | `eight
  | `nine
  | `ten
  | `eleven
  | `twelve
  | `thirteen
  | `fourteen
  | `fifteen
  | `sixteen
];