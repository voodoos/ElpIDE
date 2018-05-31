[%bs.raw {|require('./css/main.css')|}];

%raw
"var React = require('react')";

%raw
"var ReactDOM = require('react-dom')";

%raw
"window.React = React";

%raw
"window.ReactDOM = ReactDOM";

ReactDOMRe.renderToElementWithId(<App message="ElpIDE" />, "root");