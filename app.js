const path = require('path')
const fs = require('fs')

if (process.argv.length != 4) {
  console.log('Usage: node app.js ModuleName template-folder')
  console.log('Included templates:')
  console.log('    0.61+ - with support for RNW >=0.61')
  console.log('    0.62+ - with support for RNW >=0.62')
  process.exit(-1)
}
const modname = process.argv[2]
const template = process.argv[3]
const uuid = require('uuid').v4()
console.log(`Generating ${modname} with GUID {${uuid}}`)



function templaize(source, destination) {
  if (!fs.existsSync(destination)) {
    fs.mkdirSync(destination)
  }
  const files = fs.readdirSync(source)
  for (const file of files) {
    const source_file = path.join(source, file);
    const dest_file = path.join(destination, file).replace(/MODNAME/g, modname)
    if (fs.statSync(source_file).isDirectory()) {
      // handle sub-folders
      templaize(source_file, dest_file)
    } else {
      // handle files
      console.log(`${source_file} -> ${dest_file}`)
      const file_content = fs.readFileSync(source_file, 'utf8')
                             .replace(/MODNAME/g, modname)
                             .replace(/MODGUID/g, uuid)
      fs.writeFileSync(dest_file, file_content)
    }
  }
}

if (!fs.existsSync('windows')) {
  fs.mkdirSync('windows')
}
templaize(path.join(__dirname, template), path.join('windows', modname))
console.log('Be sure to update [module name here] in the README.md')
