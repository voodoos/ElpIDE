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


let toColor = (c) => Js.Option.map([@bs](a => colorToJs(a)), c);
