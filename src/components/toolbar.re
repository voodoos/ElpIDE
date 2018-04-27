let component = ReasonReact.statelessComponent("Toolbar");

let make = (~brand, ~playDisabled, ~onClickRestart, ~onClickPlay, _children) => {
  let onClickNew = (_e, _d) => Js.log("clicked");
  let onClickPlay = (_e, _d) => onClickPlay();
  let onClickRestart = (_e, _d) => onClickRestart();
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
                <Button icon=true onClick=onClickRestart>
                  <Icon name="refresh" />
                </Button>
                <Button
                  color=`blue
                  icon=true
                  onClick=onClickPlay
                  disabled=playDisabled>
                  <Icon name="settings" />
                </Button>
              </Button.Group>
            </Menu.Item>
          </Menu>
        </div>
      ),
  };
};