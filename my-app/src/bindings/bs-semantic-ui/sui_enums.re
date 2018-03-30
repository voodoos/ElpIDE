/* In this file we describe the various enumerations needed to build bindings. The [@bs.deriving jsConverter]
 * annotation will make bs generate enumnameToJs function for us. These are used in the Sui_tools module */

[@bs.deriving jsConverter]
type color = [
  | `red | `orange | `yellow | `olive | `green
  | `teal | `blue | `violet | `purple | `pink 
  | `brown | `grey | `black | `facebook 
  | [@bs.as "google plus"] `googleplus 
  | `instagram | `linkedin | `twitter | `vk
  | `youtube
];

[@bs.deriving jsConverter]
type size = [
  | `mini | `tiny | `small | `medium | `large | `big | `huge | `massive
];

[@bs.deriving jsConverter]
type attached = [
  | `left | `right | `top | `bottom
];

[@bs.deriving jsConverter]
type floated = [
  | `left | `right
];

[@bs.deriving jsConverter]
type animButton = [
  | `fade | `vertical
];


