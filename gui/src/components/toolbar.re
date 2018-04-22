let component = ReasonReact.statelessComponent("Toolbar");

let make = (~brand, ~onClickPlay, _children) => {
  let onClickNew = (_e, _d) => Js.log("clicked");
  let onClickPlay = (_e, _d) => onClickPlay();
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
              <Button.Group inverted=false>
                <Button icon=true onClick=onClickNew>
                  <Icon name="file outline" />
                </Button>
                <Button color=`olive icon=true onClick=onClickPlay>
                  <Icon name="play" />
                </Button>
              </Button.Group>
            </Menu.Item>
          </Menu>
        </div>
      ),
  };
};