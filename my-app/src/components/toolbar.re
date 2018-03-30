
let component = ReasonReact.statelessComponent("Toolbar");



let make = (~brand, ~glayout, _children) => {

    let onClickNew = (_e, _d) => {
        (glayout##root##contentItems)[0]##addChild(GoldenLayout.make_react_component("ace", [], []))
    };

    {
    ...component,

    render: _self =>
    SemanticUi.(
        <div id="navbar">
          <Menu className="header" inverted=false borderless=true>
            <Menu.Item header=true>
              (ReasonReact.stringToElement(brand))
            </Menu.Item>
            <Menu.Item>
              <Button.Group inverted=false >
                <Button icon=true onClick=onClickNew>
                  <Icon name="file outline" />
                </Button>
                <Button color=`olive icon=true>
                  <Icon name="play" />
                </Button>
              </Button.Group>
            </Menu.Item>
          </Menu>
        </div> ),
    }
  };