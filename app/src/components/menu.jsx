import React from 'react'
import { Menu } from 'semantic-ui-react'

const items = [
  { key: 'branding', header: true, name: 'Elpide' },
  { key: 'editorials', name: 'Editorials' },
  { key: 'review', name: 'Reviews' },
  { key: 'events', name: 'Upcoming Events' },
]

const MenuExampleProps = () => (
  <Menu items={items} />
)

export default MenuExampleProps
