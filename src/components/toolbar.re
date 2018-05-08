let component = ReasonReact.statelessComponent("Toolbar");

let make =
    (
      ~brand,
      ~playDisabled,
      ~onClickRestart,
      ~onClickPlay,
      ~onClickSave,
      _children,
    ) => {
  let onClickPlay = (_e, _d) => onClickPlay();
  let onClickRestart = (_e, _d) => onClickRestart();
  let onClickSave = (_e, _d) => onClickSave();
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
                <Button icon=true onClick=onClickSave>
                  <Icon name="save" />
                </Button>
                <Button icon=true onClick=onClickRestart loading=playDisabled>
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