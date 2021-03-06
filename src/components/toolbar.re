let component = ReasonReact.statelessComponent("Toolbar");

let make =
    (
      ~brand,
      ~buildInProgress,
      ~playDisabled,
      ~onClickHelp,
      ~onClickRestart,
      ~onClickPlay,
      ~onClickSave,
      ~onClickTour,
      ~onLoadFiles,
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
            <Menu.Item header=true> (ReasonReact.string(brand)) </Menu.Item>
            <Menu.Item>
              <Button.Group inverted=false>
                <LoadModal
                  trigger=(
                    onClick =>
                      <Button icon=true onClick className="jr-load">
                        <Icon name="folder open" />
                      </Button>
                  )
                  onOk=onLoadFiles
                />
                <Button icon=true onClick=onClickSave className="jr-save">
                  <Icon name="download" />
                </Button>
                <Button
                  icon=true
                  onClick=onClickRestart
                  loading=playDisabled
                  className="jr-restart">
                  <Icon name="refresh" />
                </Button>
                <Button
                  color=`blue
                  icon=true
                  onClick=onClickPlay
                  disabled=(playDisabled || buildInProgress)
                  className="jr-build">
                  <Icon name="play" />
                </Button>
              </Button.Group>
            </Menu.Item>
            <Menu.Menu position=`right>
              <Menu.Item>
                <Button.Group inverted=false>
                  <Button color=`teal onClick=onClickTour>
                    (ReasonReact.string("Take the tour !"))
                  </Button>
                  <Button
                    color=`blue
                    icon=true
                    className="jr-help"
                    onClick=onClickHelp>
                    <Icon name="help" />
                  </Button>
                </Button.Group>
              </Menu.Item>
            </Menu.Menu>
          </Menu>
        </div>
      ),
  };
};